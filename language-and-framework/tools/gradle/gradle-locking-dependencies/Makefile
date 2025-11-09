#!make

clean:
	./gradlew clean --write-locks

build:
	./gradlew build --write-locks

dependencies:
	./gradlew dependencies --write-locks

run:
	java -classpath build/libs/gradle-locking-dependencies.jar io.github.fsferrara.App
