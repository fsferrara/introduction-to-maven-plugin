# Locking dependency versions

[Official Guide](https://docs.gradle.org/current/userguide/dependency_locking.html)

## Project configuration

To generate the `gradle.lockfile` file, it is necessary to add this configuration:

```groovy
dependencyLocking {
    lockAllConfigurations()
}
```

In this example, the configuration has been added to [build.gradle](./build.gradle) file.

The `gradle.lockfile` file is generated only when adding the `--write-locks` argument to the command line. Examples are in the [Makefile](./Makefile).
