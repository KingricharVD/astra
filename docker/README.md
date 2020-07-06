Quick Docker image for Luxd
---------------------------

Build docker image:
   
    docker/build.sh

Push docker image:

    docker/push.sh

Pull Luxcore/Lux:latest from docker hub  at [Lux-dockerhub](https://hub.docker.com/r/Luxcore/Lux/)

    sudo docker pull Luxcore/Lux
    
Run docker image

    sudo docker run Luxcore/Lux

Build docker for Luxd
----------
A Docker configuration with Luxd node by default.

    sudo apt install apt-transport-https ca-certificates curl software-properties-common; curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -; sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"; sudo apt-get update; sudo apt install docker-ce   
---------------------------------------------------        
    
    mkdir Lux-mounted-data
    docker run --name Lux -d \
     --env 'LUX_RPCUSER=rpciser' \
     --env 'LUX_RPCPASSWORD=rpcpassword' \
     --env 'LUX_TXINDEX=1' \
     --volume ~/Lux-mounted-data:~/.Lux \
     -p 9888:9888 \
     --publish 9888:9888 \
     Luxcore/Lux
----------------------------------------------------
Logs

    docker logs -f Lux

----------------------------------------------------

## Configuration

Set your `Lux.conf` file can be placed in the `Lux-mounted data` dir.
Otherwise, a default `Lux.conf` file will be automatically generated based
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
$ cat /etc/systemd/system/Luxd.service

# Luxd.service #######################################################################
[Unit]
Description=Lux
After=docker.service
Requires=docker.service

[Service]
ExecStartPre=-/usr/bin/docker kill Lux
ExecStartPre=-/usr/bin/docker rm Lux
ExecStartPre=/usr/bin/docker pull Luxcore/Lux
ExecStart=/usr/bin/docker run \
    --name Lux \
    -p 9888:9888 \
    -p 9888:9888 \
    -v /data/Luxd:/root/.Lux \
    Luxcore/Lux
ExecStop=/usr/bin/docker stop Lux
```
