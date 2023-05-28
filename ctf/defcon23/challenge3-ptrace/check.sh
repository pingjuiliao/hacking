#!/bin/bash

ticket=`cat ticket`
challenge=`cat chalnum`
exploit=`cat last_build`
curl https://play.livectf.com/api/exploits/$exploit -H "X-LiveCTF-Token: $ticket"
echo ""
