//
// Created by kiper220 on 21.06.2020.
//

#include <dirent.h>
#include <sys/stat.h>
#include <Directory.h>
#include <iostream>

namespace RTL{

    Directory::Directory(){
        this->_EntityType = FSEntity::Directory;
        String string = *ApplicationDirectory;
        this->_EntityFullPath = string;
        size_t s = string.Size(), i = s - 2;
        while(string[i] != '/' && i != 0) i--;
        if(i == 0 && string[i] != '/') {
            if(string[s - 1] != '/')
                this->_EntityName = string;
            else
                this->_EntityName = string.Wrest(0, s - 1);
        }
        else{
            if(string[s - 1] != '/')
                this->_EntityName = string.Wrest(i + 1);
            else
                this->_EntityName = string.Wrest(i + 1, s - 1);
        }

        std::cout << this->_EntityName;
    }
    Directory::Directory(const String& string){
        this->_EntityType = FSEntity::Directory;
        String string1 = GetMinimizedPath(string);
        this->_EntityFullPath = string;
        size_t s = string1.Size(), i = s - 2;
        while(string1[i] != '/' && i != 0) i--;
        if(i == 0 && string[i] != '/') {
            if(string1[s - 1] != '/')
                this->_EntityName = string1;
            else
                this->_EntityName = string1.Wrest(0, s - 1);
        }
        else{
            if(string[s - 1] != '/')
                this->_EntityName = string1.Wrest(i + 1);
            else
                this->_EntityName = string1.Wrest(i + 1, s - 1);
        }

        std::cout << this->_EntityName;
    }
    Directory::Directory(const Directory& directory){
        this->_EntityName = directory._EntityName;
        this->_EntityFullPath = directory._EntityFullPath;
        this->_EntityType = FSEntityType::Directory;
    }
    Directory::Directory(Directory&& directory){
        this->_EntityName = std::move(directory._EntityName);
        this->_EntityFullPath = std::move(directory._EntityFullPath);
        this->_EntityType = FSEntityType::Directory;
    }
    bool Directory::OpenDir(){
        DIR* dir = opendir(this->_EntityFullPath);
        struct dirent *ent;
        String ignore[2] = {".", ".."};

        if(dir == nullptr) {
            this->Open = false;
            return false;
        }
        while((ent = readdir(dir)) != nullptr){
            if(ignore[0] != ent->d_name && ignore[1] != ent->d_name){
                FSEntity *entity;
                struct stat file_st;
                String directory;

                if(this->_EntityFullPath[this->_EntityFullPath.Size() - 1] != '/')
                    directory = this->_EntityFullPath + "/" + ent->d_name;
                else
                    directory = this->_EntityFullPath + ent->d_name;

                stat(directory, &file_st);

                if(S_ISDIR(file_st.st_mode)){
                    entity = new Directory(directory);
                    this->DirectoryEntities[ent->d_name] = entity;
                }else{

                }
            }
        }
        return true;
    }
    const FSEntity* Directory::operator[](const String& string){
        const FSEntity* ret = this->DirectoryEntities.GetOnly(string);
        return ret;
    }

}