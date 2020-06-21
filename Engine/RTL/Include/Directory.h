//
// Created by kiper220 on 21.06.2020.
//

#ifndef GAME_DIRECTORY_H
#define GAME_DIRECTORY_H
#include <Vector.h>
#include <String.h>

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
    class Directory {
    public:
        /**
         * Standart zero constructor
         */
        Directory();
        /**
         * Standard path constructor
         * \arg path - path to directory;
         */
        Directory(String path);
        /**
         * Standard copy constructor
         * \arg directory - target copy;
         */
        Directory(const Directory& directory);
        /**
         * Standard move constructor
         * \arg directory - target move;
         */
        Directory(const Directory&& directory);

        /**
         * Overload operator set path
         * \arg path - path to directory;
         */
        Directory& operator=(String path);
        /**
         * Overload operator copy
         * \arg directory - target copy;
         */
        Directory& operator=(const Directory& directory);
        /**
         * Overload operator move
         * \arg directory - target move;
         */
        Directory& operator=(const Directory&& directory);

        /**
         * Overload operator set path
         * \arg path - path to directory;
         */
        Directory& operator()(String path);
        /**
         * Overload operator copy
         * \arg directory - target copy;
         */
        Directory& operator()(const Directory& directory);
        /**
         * Overload operator move
         * \arg directory - target move;
         */
        Directory& operator()(const Directory&& directory);

        /**
         * Overload operator get entity method
         * \arg element - entity id in list;
         */
        const String& operator[](size_t element) const;

        /**
         * Get directory entities count method
         * \return entities count
         */
        size_t GetDirectoryEntitiesCount() const;
        /**
         * Get directory entity method
         * \arg element - entity id in list;
         */
        const String& GetDirectoryEntity(size_t element) const;
        /**
         * Get directory entities method
         * \return vector of entities
         */
        const Vector<String>& GetDirectoryEntities() const;
        /**
         * Get current path method
         * \return current directory path
         */
        const String& GetCurrentPath() const;

        /**
         * Select subdirectory method
         * \arg directory - subdir name or local path
         * \return is success
         */
        bool SelectSubdirectory(String directory);
        /**
         * Is directory open
         * \return is open
         */
        bool IsOpen() const;
    private:
        String DirectoryPath;
        Vector<String> DirectoryEntities;
        bool _IsOpen;
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
