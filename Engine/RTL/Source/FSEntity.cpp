//
// Created by kiper220 on 22.06.2020.
//

#include <FSEntity.h>

namespace RTL{
    String* FSEntity::ApplicationDirectory;
    
    String GetMinimizedPath(const String& string){
        String string1 = string;
        for (int i = 0; i < string1.Size(); ++i) {
            if(string1[i] == '.' && i != 0){
                if(string1[i - 1] != '.'){
                    if(string1[i + 1] == '.'){
                        i--;
                        if(string1[i] == '/' && string1[i + 3] == '/'){
                            int s = i - 1;
                            while(string1[s] != '/' && s != 0) s--;
                            if(s == 0 && string1[s] != '/') return String();
                            string1 = string1.Wrest(0, s) + string1.Wrest(i + 3);
                            i = s;
                        }
                    }
                    else{
                        i--;
                        if(string1[i] == '/' && string1[i + 2] == '/')
                            string1 = string1.Wrest(0, i) + string1.Wrest(i + 2);
                    }
                }else{
                    return String();
                }
            }
        }
        return string1;
    }

    String GetGlobalPath(const String& string){
        if(string[0] != '.')
            return string;
        String str = *FSEntity::ApplicationDirectory + string.Wrest(2);
        return str;
    }

    const String& FSEntity::GetEntityName(){
        return this->_EntityName;
    }
    const String& FSEntity::GetEntityFullPath(){
        return this->_EntityFullPath;
    }
    const FSEntity::FSEntityType& FSEntity::GetEntityType(){
        return this->_EntityType;
    }
}
