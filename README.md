# Coin Casino
This is a basic game that I created. You are given 100 coins and you try to push your luck as far as it will go without going out of money. I included some fun ASCII art titles for fun.

You use a basic login system, so your coins will be kept from game to game.

You can interact with the 'bank' via the `bank` application.

To play the game, clone the repo from GitHub and then simply run the downloaded executable, `coincasino`.
```
$ git clone https://github.com/TheRekrab/CoinCasino
$ ./coincasino
```

## How to play:
If you are using Windows, then you will have to recompile the source code (`coincasino.c`) to a windows-friendly executable.

Once opening the game, you will be greeted with a cool ASCII art title.
You can choose whether or not you want to play:

```
$ ./coincasino

[|=================================================================================|]
   //==\\  //==\\  ====  |\\ ||    //==\\  //-\\  //===   ====  |\\ ||  //==\\
   ||      ||  ||   ||   ||\\||    ||      ||=||  \\==\\   ||   ||\\||  ||  ||
   \\==//  \\==//  ====  || \\|    \\==//  || ||   ===//  ====  || \||  \\==//
[|=================================================================================|]


Welcome to the Coin Casino.
Would you like to play? (y/n):  y

Enter your name:
```
You will be asked for your name, so type in a username you will remember. By the way, in the username, capitalization does matter, so be careful about that. If you have not already created an account, one will be created for you with the default balance of 100 coins. If you already have an account, you can continue from where you left off last time.

Once the game starts, you can bet an amount of money on the coin flip.
Afterwards, you will be able to choose which side of the coin you think the coin will land on.

If you are right, then you will get the coins, but if you are wrong, then you will lose that many coins.
You can leave at any point in the game, but you will be forcefully kicked out if you lose all of your money.

```
[|===============================================================|]
   //==\\  //-\\  |\\  //|  ||==    //==\\  \\  //  ||==  ||=\\
   ||  __  ||=||  ||\\//||  ||=     ||  ||   \\//   ||=   ||=//
   \\==//  || ||  || \/ ||  ||==    \\==//    \/    ||==  || \\
[|===============================================================|]
```
## The Bank

If at any point in the game, you want to know how much money you have, or you want to reset your account, you can use the bank application. Launch it via:
```
$ ./bank
```
You will have 2 options:

```
[|=============================================================|]
   //==\\  //==\\  ====  |\\ ||    ||=\\  //-\\  |\\ ||  || //
   ||      ||  ||   ||   ||\\||    ||=\\  ||=||  ||\\||  ||=  
   \\==//  \\==//  ====  || \\|    ||=//  || ||  || \\|  || \\
[|=============================================================|]


Hello! Welcome to the Coin Bank.
Please login:
Name: TheRekrab
Hello, TheRekrab! Here are your options:
1 - View account balance
2 - Reset account to 100 coins
Please enter your selection here: 1
ACCOUNT BALANCE:  100 coins.
```

You may want to reset your account if you go broke and no longer have any coins.

---


That's all there is to my game. I hope you enjoy it!
