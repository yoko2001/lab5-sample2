#ifndef __DOMAIN__H__
#define __DOMAIN__H__
#include<vector>
#include<iostream>
#include "djl_type.h"
typedef struct _domain_elem{
    std::string s;
    int pos;
    _Type ty;
    _domain_elem(std::string s, int p, _Type ty):s(s), pos(p), ty(ty){}
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

    std::vector<_domain*> child_domain;
    _domain(){startline = -1; endline = -1; type = global; domainid = domain_id++; depth = 0;}
    _domain(int s, int e, domain_type t):startline(s), endline(e), type(t){domainid = domain_id++;}
    _domain(int s, int e, domain_type t, _domain* f):startline(s), endline(e), type(t), father_domain(f){domainid = domain_id++;}
    void set_f_domain(_domain* f){father_domain = f;}
    void add_s_domain(_domain* s){child_domain.push_back(s);}
    std::vector<_domain*>::iterator get_childs_iter(){std::vector<_domain*>::iterator iter = child_domain.begin(); return iter;}
    std::vector<domain_elem> elements;
    void add_element(char* s, int line, _Type ty = NULL){
        elements.push_back(domain_elem(std::string(s), line, ty));
        //std::string tab(4*depth, ' ');
        std::cout<<"domain: " <<domainid << ", added element: " << std::string(s) << " pos: " << line << std::endl;
    }
   
} domain;
/**
return the new domain, which is a son of the given domain
 */
domain* born_son_domain(domain* fa);

#endif