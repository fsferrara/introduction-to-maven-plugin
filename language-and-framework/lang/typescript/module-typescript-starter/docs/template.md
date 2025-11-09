# Template

This project template has been build with these tools.

## Node version: nvm

To switch to the right node version, use `nvm use`.
The configuration, with the node version, is in the `.nvmrc` file.

## Minimal package.json

The minimal `package.json` has been generated with `npm init -y`.
Then, it has been customized with generic feilds and the node version required (`engine.node`).
To be a module:

- The `main` attribute points at our generated JavaScript file
- Has the new `types` parameter that points it to the generated TypeScript types file
- Has a `prepublish` script to make sure that the code will be compiled before we publish the project

## Typescript dependencies

`npm i -D typescript ts-node nodemon @types/node` and then generate an initial tsc configuration with `npx tsc --init`.
The `tsconfig.json` file has been customized to use es2020, to transpile in the `dist` folder, and other common features.
In particular, setting the `declaration` attribute to `true` ensures that the compiler generates the respective TypeScript definitions files aside of compiling the TypeScript files to JavaScript files. The `outDir` parameter defines the output directory as the `dist` folder.

## Nodemon

The configuration is in the `nodemon.json` file. It is used in the `dev` and `dev:debug` scripts.
Note that the `dev:debug` script adds `--inspect-brk` flag, this tells node to halt the program execution until the debugger is attached, this can be replaced with `--inspect` flag to debug without halting.

## VS Code

The `.vscode/launch.json` has the necessary configurations to run the project from the `lib` or `dist` folders.
About the debug, there is a configuration to attach vscode to a linstening process.

## Tests

Install `jest`, `@types/jest`, `ts-jest` as development dependencies. Then, generate Jest config with `ts-jest` (e.g. `yarn ts-jest config:init`).
