![astra Logo](src/qt/res/images/astra_logo_horizontal.png)

"FIRST OF ITS KIND"

Astracore is GNU AGPLv3 licensed.

[![FOSSA Status](https://app.fossa.io/api/projects/git%2Bgithub.com%2Fastra-Core%2Fastra.svg?type=shield)](https://app.fossa.io/projects/git%2Bgithub.com%2Fastra-Core%2Fastra?ref=badge_shield) [![Build Status](https://travis-ci.org/astra-Core/astra.svg?branch=master)](https://travis-ci.org/astra-Core/astra) [![GitHub version](https://badge.fury.io/gh/astra-Core%2Fastra.png)](https://badge.fury.io/gh/astra-Core%2Fastra.png) [![HitCount](http://hits.dwyl.io/astra-Core/astra.svg)](http://hits.dwyl.io/astra-Core/astra)
<a href="https://discord.gg/4jaVvTN"><img src="https://discordapp.com/api/guilds/632270260040368138/embed.png" alt="Discord server" /></a> <a href="https://twitter.com/intent/follow?screen_name=astra_Astra"><img src="https://img.shields.io/twitter/follow/TR3B_Astra.svg?style=social&logo=twitter" alt="follow on Twitter"></a>
                                                                                                                                                     
[![Build history](https://buildstats.info/travisci/chart/astra-Core/astra?branch=master)](https://travis-ci.org/astra-Core/astra?branch=master)

[Website](https://astracore.io) — [ASTRAtre + ASTRAGate](https://github.com/astra-Core/astratre) - [PoS Web Wallet](https://astra.poswallet.io) — [Block Explorer](https://explorer.astracore.io/)  — [Telegram](https://t.me/ASTRA_Allegiance) — [Twitter](https://twitter.com/TR3B_Astra)

Features
=============

* Hybrid PoW/PoS algorithm
* Hybrid masternode
* Static PoS
* Segwit
* Smart contract
* New PHI2 PoW/PoS hybrid algorithm
* Astragate
* Parallel masternode (PMN)

  * [Banking layer](#)
  
  * [Proof of file storage (Distributed file storage (DFS))](doc/Technical-description-of-the-implementation-of-a-distributed-file-storage.md)
   
    * [DFS Testnet](doc/dfs-testnet.md)
    
* ~~PHI1612 PoW/PoS hybrid algorithm~~


The Astracore Project is a decentralized peer-to-peer banking financial platform, created under an open source license, featuring a built-in cryptocurrency, end-to-end encrypted messaging and decentralized marketplace. The decentralized network aims to provide anonymity and privacy for everyone through a simple user-friendly interface by taking care of all the advanced cryptography in the background.

The astragate allow for communications among validated blockchain with the ability to perform tasks and advanced functions. Through the use of PMN, astra is able to interact with many other popular blockchains and create a unifying bond among those ecosystems.

astra doesn't provide direct support for dapp database. Instead, a mechanism to interact with another Blockchain via astragate function where the other Blockchain can send and receive trigger function notices and international data through the astra network via PMN and astragate. PMN & astragate can also be used to interact with the centralized services such as bankers. Those centralism services can connect to the astra network for specific trigger of the astragate via PMN. It will allow for their developed autonomous system to act based on their behalf. The PMN will then be developed by the connecting Blockchain developer. Astracore will have to supply a deployment guide to assist their development. In order to assist the Centralized services, astra will need to provide a centralized trustworthy environments. So the user has their trusted oversight to verify that the transactions are legitimate.

In addition, without astragate and PMN, Bitcoin and Ethereum cannot interact with each other on the same Blockchain because the technology is incompatible. It is almost impossible before our PMN and astragate functions are implemented. Therefore, we have to introduce a Smartcontract & Segwit features in the next release to verify that we succeed to combine those different technologies together to create a brand new unique feature of astra.

## Coin Specifications

| Specification | Value |
|:-----------|:-----------|
| Total Blocks | `6,000,000` |
| Block Size | `4MB` |
| Block Time | `60s` |
| PoW Block Time | `120s`   |
| PoW Reward | `10 astra` |
| PoS Reward | `1 astra` |
| Stake Time | `36 hours` | 
| Masternode Requirement | `16,120 astra` |
| Masternode Reward | `20% PoW/PoS` |
| Port | `26969` |
| RPC Port | `9888` |
| Masternode Port | `26969` |
| astra legacy address start with | `L` |
| p2sh-segwit address start with | `S` |
| Bech32 address start with | `bc` |

* NOTE: "getrawchangeaddress p2sh-segwit" to get p2sh-segwit address 

Instructions
-----------
* [astra-qt](doc/astra_QT_v5_Win_Mac_User_Guide.pdf)

* [Smart contract](doc/smartcontract.md)

* [Token](doc/Token_Instructionsv2.pdf) (Thanks @snowfro)

* [DFS Testnet](doc/dfs-testnet.md)


Development Process
-------------------

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/astra-Core/astra/tags) are created
regularly to indicate new official, stable release versions of astra.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).


Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/qa) of the RPC interface, written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/qa) are installed) with: `qa/pull-tester/rpc-tests.py`

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

### Issue

 We try to prompt our users for the basic information We always need for new issues.
 Please fill out the issue template below and submit it to our discord channel
  <a href="https://discord.gg/ndUg9va"><img src="https://discordapp.com/api/guilds/364500397999652866/embed.png" alt="Discord server" /></a>
 
 [ISSUE_TEMPLATE](doc/template/ISSUE_TEMPLATE_example.md)

## License
[![FOSSA Status](https://app.fossa.io/api/projects/git%2Bgithub.com%2Fastra-Core%2Fastra.svg?type=large)](https://app.fossa.io/projects/git%2Bgithub.com%2Fastra-Core%2Fastra?ref=badge_large)
