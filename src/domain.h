#ifndef __DOMAIN__H__
#define __DOMAIN__H__
#include<vector>
#include<iostream>
//#include"inter.h"
#include "djl_type.h"

//domain element kind
enum {
    DEK_Tag, DEK_Constant, DEK_variable, DEK_Temp, DEK_Offset, 
    DEK_String, DEK_label, DEK_function, DEK_Register,
};

typedef struct _domain_elem{
    std::string *s;  //name
    int pos;        //lineno
    _Type ty;       //sysType
    int kind;

    int ref;

    int intval;
    char ch_val;
    //bool b_val;
    std::string str_val;

    struct _domain* dm;


    bool defined;   //if just declared or already defined
    _domain_elem(std::string s, int p, _Type ty):pos(p), ty(ty){
        this->s = new std::string(s);
    }
    _domain_elem(){}
} domain_elem;
enum domain_type{
    global = 0,
    block_domain = 1,
}; 
typedef struct _domain{
    static int domain_id;
    int startline, endline, domainid, depth;
    domain_type type;
    _domain* father_domain;
    void* entryBB;
    void* exitBB;
    std::vector<_domain*> child_domain;
    _domain(){startline = -1; endline = -1; type = global; domainid = domain_id++; depth = 0;}
    _domain(int s, int e, domain_type t):startline(s), endline(e), type(t){domainid = domain_id++;}
    _domain(int s, int e, domain_type t, _domain* f):startline(s), endline(e), type(t), father_domain(f){domainid = domain_id++;}
    void set_f_domain(_domain* f){father_domain = f;}
    void add_s_domain(_domain* s){child_domain.push_back(s);}
    std::vector<_domain*>::iterator get_childs_iter(){std::vector<_domain*>::iterator iter = child_domain.begin(); return iter;}
    std::vector<domain_elem*> elements;
    void add_element(char* s, int line, _Type ty = NULL){
        elements.push_back(new domain_elem(std::string(s), line, ty));
        //std::string tab(4*depth, ' ');
        std::cout<<"domain: " <<domainid << ", added element: " << std::string(s) << " pos: " << line << std::endl;
    }
    void add_element(domain_elem* e){
       elements.push_back(e);
       e->dm = this;
       std::cout<<"domain: " <<domainid << ", added element: " << *(e->s) << " pos: " << e->pos << std::endl;
    }
} domain;
/**
return the new domain, which is a son of the given domain
 */
domain* born_son_domain(domain* fa);

domain_elem* LookupID(domain* dm, std::string name);

void copyfrom(domain_elem*src, domain_elem* dst);
#endif