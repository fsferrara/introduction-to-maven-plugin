# Notes

To generate the project I used SPM (Swift Package Manager): `swift package init --type executable`.
Then I added a test.

Useful SPM command are documented in the [Makefile](./Makefile).

The recommended way to generate an Xcode project for your Swift package is to open the Package.swift file in Xcode. Xcode will automatically generate an Xcode project file for your package.

## Conventions to use!

- In the `Package.swift` use the PascalCase for identifiers (package name, products, targets)
- The package name should match with the root folder name. Both have to be PascalCase
- 