URL=https://kylin.eos.dfuse.io
ACCOUNT=depositcheck
FILENAME=depositcheck
#cleos -u $URL set abi $ACCOUNT $FILENAME.abi
cleos -u $URL set code $ACCOUNT $FILENAME.wasm
