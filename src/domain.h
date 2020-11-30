#ifndef __DOMAIN__H__
#define __DOMAIN__H__
#include<vector>
#include<iostream>
#include "djl_type.h"
#include "position.h"
typedef struct _domain_elem{
    std::string s;
    position pos;
    _Type ty;
    _domain_elem(std::string s, position p, _Type ty):s(s), pos(p), ty(ty){}
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
    void add_element(char* s, int row, int col, _Type ty = NULL){
        elements.push_back(domain_elem(std::string(s), position(row, col), ty));
        std::string tab(4*depth, ' ');
        //std::cout << tab<<"domain: " <<domainid << ", added element: " << std::string(s) << " pos: " << row << ", " << col << " ";
    }
   
} domain;
std::ostream & operator<<(std::ostream& os,  const _domain & d){
    os << "domain id: " << d.domainid << std::endl;
    os << "elements: " << std::endl;
    for(int i = 0; i < d.elements.size(); i++){
        os << "    "<<d.elements[i].s << ' ' << d.elements[i].pos << std::endl;
    }
    os << "-------------------------------------\n";
    for(int i = 0; i < d.child_domain.size(); i++){
        os << *(d.child_domain[i]);
    }
    return os;
}
/**
return the new domain, which is a son of the given domain
 */
domain* born_son_domain(domain* fa){
    domain* son = new domain(0, 0, block_domain);
    son->set_f_domain(fa);
    fa->add_s_domain(son);
    son->depth = fa->depth+1;
    return son;
}

int domain::domain_id = 0; //初始化
#endif