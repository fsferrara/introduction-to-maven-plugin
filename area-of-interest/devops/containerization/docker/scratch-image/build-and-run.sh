#! /bin/bash

echo "Building the image..."
docker image build -t custom-hello:latest .
echo "Running the image..."
docker run custom-hello