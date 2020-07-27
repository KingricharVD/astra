### Build on OSX

The commands in this guide should be executed in a Terminal application.
The built-in one is located in `/Applications/Utilities/Terminal.app`.

#### Preparation

Install the OS X command line tools:

`xcode-select --install`

When the popup appears, click `Install`.

If you're running macOS Mojave 10.14/Xcode 10.0 or later, and want to use the depends system, you'll also need to use the following script to install the macOS system headers into /usr/include.

    open /Library/Developer/CommandLineTools/Packages/macOS_SDK_headers_for_macOS_10.14.pkg

Then install [Homebrew](https://brew.sh)

    /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

#### Dependencies

    brew install cmake automake berkeley-db4 leveldb libtool boost@1.64 --c++11 --without-single --without-static miniupnpc openssl pkg-config protobuf qt5 libevent imagemagick --with-librsvg

Link boost 1.64

    brew link boost@1.64 --force

#### Build Astracore

Clone the astra source code and cd into astra

        git clone https://github.com/CryptoLover705/AstraCoin_2.0 astra
        cd astra
        ./building/mac/requirements.sh
        ./building/mac/build.sh
