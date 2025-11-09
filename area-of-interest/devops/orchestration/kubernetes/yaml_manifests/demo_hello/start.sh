#! /usr/bin/env sh

kubectl="minikube kubectl --"

$kubectl apply -f k8s/
$kubectl port-forward service/demo 9999:8888

open "http://localhost:9999/"

