//
// Created by kiper220 on 22.06.2020.
//

#ifndef GAME_FSENTITY_H
#define GAME_FSENTITY_H

#include <RTL/String.h>


// TODO: Check, refactoring and add exception processing. Add comments

#define GLOBALDIR_INIT()                                                                \
RTL::String ApplicationDirectory = args[0];                                             \
int i;                                                                                  \
for (i = ApplicationDirectory.Size(); i >= 0 && ApplicationDirectory[i] != '/'; i--);   \
if(i == 0)                                                                              \
ApplicationDirectory = "/";                                                             \
else                                                                                    \
ApplicationDirectory.Cut(0, i + 1);                                                     \
                                                                                        \
RTL::FSEntity::ApplicationDirectory = &ApplicationDirectory;                            \

namespace RTL::Types{

    String GetMinimizedPath(const String& string);
    String GetGlobalPath(const String& string);

    class FSEntity {
    public:
        enum FSEntityType{
            Directory,
            File
        };

        const String& GetEntityName();
        const String& GetEntityFullPath();
        const FSEntity::FSEntityType& GetEntityType();

        static const String ApplicationDirectory;
    protected:
        String _EntityName;
        String _EntityFullPath;
        FSEntityType _EntityType;
        bool Open;
    };
}

#endif //GAME_FSENTITY_H
