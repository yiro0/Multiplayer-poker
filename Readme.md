# Multiplayer Poker Game

## About the Project

This project was developed as part of the **Computer Programming 2** course during the second semester.


## Overview

The project is a multiplayer poker game application built using C++. It consists of a server that manages poker game logic, client connections, and communication, as well as a client that interacts with the server to participate in the game.

---
## Features

### Server
- **Client Management**: Handles multiple client connections using `pthread`.
- **Game Logic**: Implements poker-specific rules, including hand evaluation, betting rounds, and player actions.
- **Command Processing**: Supports various server and client commands for game control.
- **Messaging**: Broadcasts messages to clients and handles individual client communication.

### Client
- **Command Execution**: Sends commands to the server to perform poker actions (e.g., bet, fold, raise).
- **Server Interaction**: Receives game updates, messages, and results from the server.

##  Project Logic

The project implements a multiplayer poker game with a server-client architecture. Below is an overview of how the project logic works:

###  Server Logic
The server is responsible for managing the game and client interactions. It performs the following tasks:
-  **Client Management**: Handles multiple client connections using `pthread`, ensuring smooth communication and synchronization.
-  **Game Flow Management**: Controls the flow of the poker game, including dealing cards, managing betting rounds, and determining winners.
-  **Command Processing**: Processes commands sent by clients (e.g., `bet`, `fold`, `raise`) and executes corresponding actions.
-  **Messaging**: Sends game updates, messages, and results to clients.

###  Client Logic
The client interacts with the server to participate in the game. It performs the following tasks:
-  **Command Execution**: Sends commands to the server to perform poker actions such as betting, folding, or raising.
-  **Game Updates**: Receives updates from the server, including the current game state, player actions, and results.


##  How the Poker Game Works

The poker game implemented in this project follows the rules of a standard poker game with the following features:

- **Deck Management**:
   - A standard 52-card deck is shuffled and managed by the `DeckMaster` class.
   - Cards are dealt to players at the start of the game and during specific phases.

- **Player Actions**:
   - Players can perform actions such as `bet`, `raise`, `fold`, `check`, and `call` during their turn.
   - Commands are sent from the client to the server, which processes them and updates the game state.

- **Betting Rounds**:
   - The game includes multiple betting rounds where players can place bets, raise, or fold.
   - The server manages the pot and ensures that all players meet the current bet to stay in the game.

- **Hand Evaluation**:
   - At the end of the game, the server evaluates the hands of the remaining players using the `Evaluator` class.
   - The player with the best hand wins the pot.

- **Game Flow**:
   - The game progresses through the following stages:
     - **Dealing**: Cards are dealt to players.
     - **Betting Rounds**: Players place bets or take actions.
     - **Showdown**: Remaining players reveal their hands, and the winner is determined.
   - The server ensures that the game flow is synchronized across all connected clients.

## Project Structure

### Server Directory
- **`Server/Server.h` and `Server/Server.cpp`**: Core server implementation, including client handling, message broadcasting, and game management.
- **`Connections/ClientConnection.h` and `Connections/ConnectionManager.h`**: Manage client connections and interactions.
- **`Game/`**: Contains poker game logic, including:
  - `Game.h` and `Game.cpp`: Main game logic.
  - `Player.h` and `Player.cpp`: Player management.
  - `DeckMaster.h` and `DeckMaster.cpp`: Card deck management.
  - `Evaluator.h` and `Evaluator.cpp`: Poker hand evaluation logic.
- **`Command/`**: Command processing for both server and client:
  - `ServerCommand/`: Server-specific commands like `StopCommand` and `ServerInfoCommand`.
  - `ClientCommand/`: Client-specific commands like `BetCommand`, `RaiseCommand`, and `FoldCommand`.
- **`ServerMessageSender.h` and `MessagePrinter.h`**: Handle server-to-client communication.

### Client Directory (Assumed)
- **Client Commands**: Includes commands for interacting with the server, such as `BetCommand`, `RaiseCommand`, and `FoldCommand`.

## Commands

### Server Commands
The server supports the following commands to manage the game and server operations:
- **`stop`**: Stops the server and disconnects all clients.
- **`serverinfo`**: Displays information about the server, including connected clients and game status.


### Client Commands
Clients can use the following commands to interact with the game:
- **`bet <amount>`**: Places a bet with the specified amount.
- **`raise <amount>`**: Raises the current bet by the specified amount.
- **`fold`**: Folds the current hand and exits the round.
- **`check`**: Checks without betting if no bet is required.
- **`call`**: Matches the current highest bet.
- **`all`**: Goes all-in with the remaining chips.
- **`exchange <cards>`**: Exchanges specified cards during the exchange phase (if applicable).
- **`bye`**: Disconnects the client from the server.
- **`cya`**: Leaves the game and disconnects from the server.
- **`help`**: Displays a list of available commands.
- **`invalid`**: Handles invalid or unrecognized commands.

These commands allow players to fully participate in the poker game and interact with the server effectively
