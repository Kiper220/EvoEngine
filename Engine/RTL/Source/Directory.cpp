//
// Created by kiper220 on 21.06.2020.
//

#include <dirent.h>
#include <sys/stat.h>
#include <Directory.h>

namespace RTL{

    bool IsDir(String path){
        struct stat path_stat;
        stat(path, &path_stat);
        return S_ISDIR(path_stat.st_mode);
    }

    int FileCount(Directory dir){
        if(!dir.IsOpen()) return 0;
        int s = 0;
        for(const String &item : dir.GetDirectoryEntities()){
            if(IsDir(dir.GetCurrentPath() + item)) s += FileCount(dir.GetCurrentPath() + item);
            else s++;
        }
        return s;
    }
    int EntitiesCount(Directory dir){
        if(!dir.IsOpen()) return 0;
        int s = 0;
        for(const String &item : dir.GetDirectoryEntities()){
            if(IsDir(dir.GetCurrentPath() + item)) s += EntitiesCount(dir.GetCurrentPath() + item) + 1;
            else s++;
        }
        return s;
    }
    int DirectoriesCount(Directory dir){
        if(!dir.IsOpen()) return 0;
        int s = 0;
        for(const String &item : dir.GetDirectoryEntities()){
            if(IsDir(dir.GetCurrentPath() + item)) s += DirectoriesCount(dir.GetCurrentPath() + item) + 1;
        }
        return s;
    }

    Directory::Directory(){
        DIR* dir = opendir(".");
        String str[2] = {".", ".."};
        if(dir != nullptr){
            this->_IsOpen = true;
            this->DirectoryPath = "./";
            dirent* entity;
            while((entity = readdir(dir)) != nullptr){
                if(str[0] != entity->d_name && str[1] != entity->d_name)
                    this->DirectoryEntities.Push_Back(entity->d_name);
            }
        }
        else this->_IsOpen = false;
        closedir(dir);
    }
    Directory::Directory(String path):  _IsOpen(false){
        if(path.IsEmpty())
            path = "./";

        DIR* dir = opendir(path);
        String str[2] = {".", ".."};
        if(dir != nullptr){
            this->_IsOpen = true;
            this->DirectoryPath = std::move(path);
            if(this->DirectoryPath[this->DirectoryPath.Size() - 1] != '/')
                this->DirectoryPath += "/";

            dirent* entity;
            while((entity = readdir(dir)) != nullptr){
                if(str[0] != entity->d_name && str[1] != entity->d_name)
                    this->DirectoryEntities.Push_Back(entity->d_name);
            }
        }else this->_IsOpen = false;

        closedir(dir);
    }
    Directory::Directory(const Directory& directory):  _IsOpen(false){
        if(!directory._IsOpen) return;
        if(directory.DirectoryPath.IsEmpty()) {
            (*this)("./");
            return;
        }

        DIR* dir = opendir(directory.DirectoryPath);
        String str[2] = {".", ".."};
        if(dir != nullptr){
            this->_IsOpen = true;
            this->DirectoryPath = directory.DirectoryPath;

            dirent* entity;
            while((entity = readdir(dir)) != nullptr){
                if(str[0] != entity->d_name && str[1] != entity->d_name)
                    this->DirectoryEntities.Push_Back(entity->d_name);
            }
        }else this->_IsOpen = false;

        closedir(dir);
    }
    Directory::Directory(const Directory&& directory):  _IsOpen(false){
        if(!directory._IsOpen) return;
        this->DirectoryPath = std::move(directory.DirectoryPath);
        this->DirectoryEntities = std::move(directory.DirectoryEntities);
    }

    Directory& Directory::operator=(String path){
        if(path.IsEmpty()) {
            path = "./";
        }
        this->DirectoryEntities.Clear();
        this->DirectoryPath.Clear();

        DIR* dir = opendir(path);
        String str[2] = {".", ".."};
        if(dir != nullptr){
            this->_IsOpen = true;
            this->DirectoryPath = std::move(path);
            if(this->DirectoryPath[this->DirectoryPath.Size() - 1] != '/')
                this->DirectoryPath += "/";

            dirent* entity;
            while((entity = readdir(dir)) != nullptr){
                if(str[0] != entity->d_name && str[1] != entity->d_name)
                    this->DirectoryEntities.Push_Back(entity->d_name);
            }
        } else this->_IsOpen = false;
        closedir(dir);
        return *this;
    }
    Directory& Directory::operator=(const Directory& directory){
        if(directory.DirectoryPath.IsEmpty()) {
            (*this)("./");
            return *this;
        }
        this->DirectoryEntities.Clear();
        this->DirectoryPath.Clear();

        DIR* dir = opendir(directory.DirectoryPath);
        String str[2] = {".", ".."};
        if(dir != nullptr){
            this->_IsOpen = true;
            this->DirectoryPath = directory.DirectoryPath;

            dirent* entity;
            while((entity = readdir(dir)) != nullptr){
                if(str[0] != entity->d_name && str[1] != entity->d_name)
                    this->DirectoryEntities.Push_Back(entity->d_name);
            }
        } else this->_IsOpen = false;
        closedir(dir);
        return *this;
    }
    Directory& Directory::operator=(const Directory&& directory){
        this->DirectoryPath = std::move(directory.DirectoryPath);
        this->DirectoryEntities = std::move(directory.DirectoryEntities);
        this->_IsOpen = directory._IsOpen;
        return *this;
    }

    Directory& Directory::operator()(String path){
        *this = path;
    }
    Directory& Directory::operator()(const Directory& directory){
        *this = directory;
    }
    Directory& Directory::operator()(const Directory&& directory){
        *this = directory;
    }

    const String& Directory::operator[](size_t element) const{
        return this->DirectoryEntities[element];
    }

    size_t Directory::GetDirectoryEntitiesCount() const{
        return this->DirectoryEntities.Size();
    }
    const String& Directory::GetDirectoryEntity(size_t element) const{
        return this->DirectoryEntities[element];
    }
    const Vector<String>& Directory::GetDirectoryEntities() const{
        return this->DirectoryEntities;
    }
    const String& Directory::GetCurrentPath() const{
        return this->DirectoryPath;
    }

    bool Directory::SelectSubdirectory(String directory){
        if(directory[0] == '/')
            directory.Cut(1);
        directory = this->DirectoryPath + directory;

        DIR* dir = opendir(directory);
        String str[2] = {".", ".."};
        if(dir != nullptr) {
            this->_IsOpen = true;
            this->DirectoryEntities.Clear();

            this->DirectoryPath = directory;

            dirent* entity;
            while((entity = readdir(dir)) != nullptr){
                if(str[0] != entity->d_name && str[1] != entity->d_name)
                    this->DirectoryEntities.Push_Back(entity->d_name);
            }
            return true;
        }
        else this->_IsOpen = false;
        return false;
    }

    bool Directory::IsOpen() const{
        return this->_IsOpen;
    }
}