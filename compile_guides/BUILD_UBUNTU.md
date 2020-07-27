### Build on Ubuntu

Use

    sudo add-apt-repository ppa:bitcoin/bitcoin; git clone https://github.com/CryptoLover705/AstraCoin_2.0 astra; cd astra; depends/install-dependencies.sh; ./autogen.sh; ./configure --disable-tests --with-boost-libdir=/usr/local/lib; make clean; make -j$(nproc)


Add bitcoin repository for Berkeley DB 4.8

    sudo add-apt-repository ppa:bitcoin/bitcoin

Clone astra repository

    git clone https://github.com/CryptoLover705/AstraCoin_2.0 astra

Build astra 

    cd astra
    ./depends/install-dependencies.sh
    ./autogen.sh
    ./configure --disable-tests
    make -j$(nproc)
