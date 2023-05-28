#!/bin/bash

ticket=`cat ticket`
challenge=`cat chalnum`
tar czf solution.tar.gz Dockerfile solve.py
id=`curl https://play.livectf.com/api/challenges/$challenge -F exploit=@solution.tar.gz -H "X-LiveCTF-Token: $ticket" | jq -r '.exploit_id'`
echo $id > last_build
curl https://play.livectf.com/api/exploits/$id -H "X-LiveCTF-Token: $ticket"
echo ""
