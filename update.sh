#!/bin/bash

echo "Updating..."
mkdir /tmp/accounts_while_updating
mv Accounts/* /tmp/accounts_while_updating
cd ..
rm -rf CoinCasino
git clone https://github.com/TheRekrab/CoinCasino
cd CoinCasino
mkdir Accounts
mv /tmp/accounts_while_updating/* Accounts/
rmdir /tmp/accounts_while_updating/
echo "Done!"
echo "If you did not source this file, you may have to exit and then reenter this directory, otherwise it will look like all of the files are gone."
