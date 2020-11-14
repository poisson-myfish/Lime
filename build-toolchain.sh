mkdir toolchain
echo "Downloading and extracting binutils in toolchain/binutils/download"
mkdir -p toolchain/binutils/download
cd toolchain/binutils/download
wget https://ftp.gnu.org/gnu/binutils/binutils-2.35.1.tar.gz
tar -xf ./binutils-2.35.1.tar.gz

echo "Exporting environment variables"
cd ..
export PREFIX="`pwd`"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

echo "Building binutils"
ls ./download
./download/binutils-2.35.1/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install
