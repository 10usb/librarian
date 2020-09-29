#include <sunit/storage/table.hpp>

using namespace sunit::storage;

Table::Table(const char *path){

}

sunit::storage::Table::~Table(){

}

void Table::addField(const char *name, sl::DataType type, int32_t size){

}

void Table::removeField(const char *name, sl::DataType type, int32_t size){

}

sl::Result *Table::getFields(){
    return 0;
}

void Table::addIndex(const char *name, const sl::FieldSet &fields){

}

void Table::removeIndex(const char *name){

}

sl::Result *Table::getIndexes(){
    return 0;
}

sl::Result *Table::getIndexFields(const char *name){
    return 0;
}

sl::Result *Table::insert(const sl::DataSet *data){
    return 0;
}

sl::Result *Table::select(const sl::Query *query){
    return 0;
}

sl::Result *Table::remove(const sl::DataSet *key){
    return 0;
}

sl::Result *Table::update(const sl::DataSet *key, const sl::DataSet *data){
    return 0;
}