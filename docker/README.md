Quick Docker image for astrad
---------------------------

Build docker image:
   
    docker/build.sh

Push docker image:

    docker/push.sh

Pull astracore/astra:latest from docker hub  at [astra-dockerhub](https://hub.docker.com/r/astracore/astra/)

    sudo docker pull astracore/astra
    
Run docker image

    sudo docker run astracore/astra

Build docker for astrad
----------
A Docker configuration with astrad node by default.

    sudo apt install apt-transport-https ca-certificates curl software-properties-common; curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -; sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"; sudo apt-get update; sudo apt install docker-ce   
---------------------------------------------------        
    
    mkdir astra-mounted-data
    docker run --name astra -d \
     --env 'ASTRA_RPCUSER=rpciser' \
     --env 'ASTRA_RPCPASSWORD=rpcpassword' \
     --env 'ASTRA_TXINDEX=1' \
     --volume ~/astra-mounted-data:~/.astra \
     -p 9888:9888 \
     --publish 9888:9888 \
     astracore/astra
----------------------------------------------------
Logs

    docker logs -f astra

----------------------------------------------------

## Configuration

Set your `astra.conf` file can be placed in the `astra-mounted data` dir.
Otherwise, a default `astra.conf` file will be automatically generated based
on environment variables passed to the container:

| name | default |
| ---- | ------- |
| BTC_RPCUSER | rpcuser |
| BTC_RPCPASSWORD | rpcpassword |
| BTC_RPCPORT | 9888 |
| BTC_RPCALLOWIP | ::/0 |
| BTC_RPCCLIENTTIMEOUT | 30 |
| BTC_DISABLEWALLET | 1 |
| BTC_TXINDEX | 0 |
| BTC_TESTNET | 0 |
| BTC_DBCACHE | 0 |
| BTC_ZMQPUBHASHTX | tcp://0.0.0.0:28333 |
| BTC_ZMQPUBHASHBLOCK | tcp://0.0.0.0:28333 |
| BTC_ZMQPUBRAWTX | tcp://0.0.0.0:28333 |
| BTC_ZMQPUBRAWBLOCK | tcp://0.0.0.0:28333 |


## Daemonizing

If you're daemonizing is to use Docker's 
[Daemonizing](https://docs.docker.com/config/containers/start-containers-automatically/#use-a-restart-policy),
but if you're insistent on using systemd, you could do something like

```
$ cat /etc/systemd/system/astrad.service

# astrad.service #######################################################################
[Unit]
Description=Astra
After=docker.service
Requires=docker.service

[Service]
ExecStartPre=-/usr/bin/docker kill astra
ExecStartPre=-/usr/bin/docker rm astra
ExecStartPre=/usr/bin/docker pull astracore/astra
ExecStart=/usr/bin/docker run \
    --name astra \
    -p 9888:9888 \
    -p 9888:9888 \
    -v /data/astrad:/root/.astra \
    astracore/astra
ExecStop=/usr/bin/docker stop astra
```
