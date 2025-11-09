# Template

This project template has been build with these tools.

## Node version: nvm

To switch to the right node version, use `nvm use`.
The configuration, with the node version, is in the `.nvmrc` file.

## Minimal package.json

The minimal `package.json` has been generated with `npm init -y`.
Then, it has been customized with generic feilds and the node version required (`engine.node`).

## Typescript dependencies

`npm i -D typescript ts-node nodemon @types/node` and then generate an initial tsc configuration with `npx tsc --init`.
The `tsconfig.json` file has been customized to use es2020, to transpile in the `dist` folder, and other common features.

## Nodemon

The configuration is in the `nodemon.json` file. It is used in the `dev` and `dev:debug` scripts.
Note that the `dev:debug` script adds `--inspect-brk` flag, this tells node to halt the program execution until the debugger is attached, this can be replaced with `--inspect` flag to debug without halting.

## VS Code

The `.vscode/launch.json` has the necessary configurations to run the project from the `src` or `dist` folders.
About the debug, there is a configuration to attach vscode to a linstening process.
