//
// Created by kiper220 on 21.06.2020.
//

#ifndef GAME_DIRECTORY_H
#define GAME_DIRECTORY_H
#include <FSEntity.h>
#include <Map.h>

namespace RTL {

    /**
     * path is directory function
     * \arg path - path to entity
     * \return path is directory
     */
    bool IsDir(String path);
    /**
     *
     * \brief Red Template Library Directory class
     * \authors WetGrape | kiper220
     *
     */
    class Directory : public FSEntity{
    public:
        Directory();
        Directory(const String& string);
        Directory(const Directory& directory);
        Directory(Directory&& directory);

        bool OpenDir();

        const FSEntity* operator[](const String& string);


        
    private:
        Map<String, FSEntity*> DirectoryEntities;
    };
    /**
     * File count
     * \arg directory - root directory
     * \return file entities count
     */
    int FileCount(Directory directory);
    /**
     * Entities count
     * \arg directory - root directory
     * \return entities count
     */
    int EntitiesCount(Directory dir);
    /**
     * Directories count
     * \arg directory - root directory
     * \return directories entities count
     */
    int DirectoriesCount(Directory dir);

}
#endif //GAME_DIRECTORY_H
