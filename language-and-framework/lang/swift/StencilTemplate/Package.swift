// swift-tools-version: 5.8
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "StencilTemplate",
    products: [
        .executable(name: "stencil-template", targets: ["StencilTemplate"])
    ],
    dependencies: [
        .package(url: "https://github.com/stencilproject/Stencil.git", from: "0.15.1"),
    ],
    targets: [
        .executableTarget(
            name: "StencilTemplate",
            dependencies: [
               .product(name: "Stencil", package: "Stencil"),
            ]
        )
    ]
)
