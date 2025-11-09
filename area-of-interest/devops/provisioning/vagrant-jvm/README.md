# Scala SBT

````
#!/bin/bash
SBT_OPTS="-Xms512M -Xmx1536M -Xss1M -XX:+CMSClassUnloadingEnabled -XX:MaxPermSize=512M"
java $SBT_OPTS -jar `dirname $0`/sbt-launch.jar "$@"
````

# Clojure

````
#!/bin/bash
java -cp $CLOJURE_HOME/clojure-1.6.0.jar clojure.main $1 $2 $3 $4 $5
````
