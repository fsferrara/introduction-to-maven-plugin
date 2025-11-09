package com.fsferrara.java.filetostring;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.net.URL;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Component;

@Component
public class FileResponse {
    private static final Logger LOGGER = LoggerFactory.getLogger(FileResponse.class);

    public String read() {
        File file = getFileFromResources("static/response.json");
        return printFile(file);
    }

    // get file from classpath, resources folder
    private File getFileFromResources(String fileName) {

        ClassLoader classLoader = getClass().getClassLoader();

        URL resource = classLoader.getResource(fileName);
        if (resource == null) {
            throw new IllegalArgumentException("file is not found!");
        } else {
            return new File(resource.getFile());
        }

    }

    private String printFile(File file) {

        if (file == null) return null;
        StringBuilder content = new StringBuilder();

        try (FileReader reader = new FileReader(file);
             BufferedReader br = new BufferedReader(reader)) {

            String line;
            while ((line = br.readLine()) != null) {
                content.append(line);
            }
        } catch (IOException ex) {
            LOGGER.error("Error while reading from file");
        }

        return content.toString();
    }

}
