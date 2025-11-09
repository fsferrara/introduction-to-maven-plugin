subprojects {
    tasks.register<Copy>("dist") {
        dependsOn("jar")
        from("${project.rootDir}/scripts/app")
        from("${project.projectDir}/build/libs/${project.name}.jar") {
            into("lib")
        }
        into("${project.rootDir}/dist")
    }
}

