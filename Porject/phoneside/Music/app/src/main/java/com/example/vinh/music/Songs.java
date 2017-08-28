package com.example.vinh.music;

/**
 * Created by Vinh on 8/28/2017.
 */

public class Songs {
    private String name;
    private int file;

    public Songs(String name, int file) {
        this.name = name;
        this.file = file;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getFile() {
        return file;
    }

    public void setFile(int file) {
        this.file = file;
    }
}
