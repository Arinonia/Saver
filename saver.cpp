#include "saver.h"
#include <iostream>
Saver::Saver(QFile &file){
    this->file = &file;
    this->p = cppproperties::Properties();
    if (file.exists()){
        load();
    }
}
std::string Saver::get(std::string key){
    return this->p.GetProperty(key);
}
void Saver::put(std::string key, std::string value){
    this->p.AddProperty(key, value);
    this->save();
}
void Saver::load(){
   std::cout << "File is load\n";
    cppproperties::PropertiesParser::Read(this->file->fileName().toUtf8().toStdString());
}
void Saver::save(){
 cppproperties::PropertiesParser::Write(this->file->fileName().toUtf8().toStdString(), this->p);
}

