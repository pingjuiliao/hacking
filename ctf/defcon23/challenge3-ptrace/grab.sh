#!/bin/bash

challengeId=`cat chalnum`

wget https://play.livectf.com/api/challenges/$challengeId/download -O challenge$challengeId.tar.gz
