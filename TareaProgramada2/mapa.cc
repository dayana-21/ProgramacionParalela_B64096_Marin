#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include "mapa.h"

using namespace std;
std::map <string,int> tags;
	std::map <string,int>::iterator iter;//iterador del mapa
	int cantidad;


mapa::mapa(){
std::map <string,int> tags;
}

void mapa::asignarMapa(){
	tags["!--"]=0;
	tags["a"]=0; 
	tags["/a"]=0; 	
	tags["abbr"]=0;
	tags["/abbr"]=0;
	tags["address"]=0; 
	tags["/address"]=0;
	tags["area"]=0;
	tags["/area"]=0;
	tags["article"]=0;
	tags["/article"]=0;
	tags["aside"]=0;
	tags["/aside"]=0;
	tags["audio"]=0;
	tags["/audio"]=0;
	tags["b"]=0;
	tags["/b"]=0;
	tags["base"]=0;
	tags["/base"]=0;
	tags["bdi"]=0; 
	tags["/bdi"]=0; 
	tags["bdo"]=0;
	tags["/bdo"]=0;
	tags["blockquote"]=0;
	tags["/blockquote"]=0;
	tags["body"]=0;
	tags["/body"]=0;
	tags["br"]=0;
	tags["/br"]=0;
	tags["button"]=0;
	tags["/button"]=0;
	tags["canvas"]=0;
	tags["/canvas"]=0;
	tags["caption"]=0;
	tags["/caption"]=0;
	tags["cite"]=0;	
	tags["/cite"]=0;	
	tags["code"]=0;	
	tags["/code"]=0;	
	tags["col"]=0;	
	tags["/col"]=0;
	tags["colgroup"]=0;	
	tags["/colgroup"]=0;	
	tags["command"]=0;
	tags["/command"]=0;
	tags["datalist"]=0;	
	tags["/datalist"]=0;	
	tags["dd"]=0;	
	tags["/dd"]=0;	
	tags["del"]=0;	
	tags["/del"]=0;	
	tags["details"]=0;	
	tags["/details"]=0;	
	tags["dfn"]=0;	
	tags["/dfn"]=0;	
	tags["dialog"]=0;
	tags["/dialog"]=0;		
	tags["div"]=0;	
	tags["/div"]=0;
	tags["dl"]=0;	
	tags["/dl"]=0;
	tags["dt"]=0;	
	tags["/dt"]=0;	
	tags["em"]=0;	
	tags["/em"]=0;	
	tags["embed"]=0;
	tags["/embed"]=0;
	tags["fieldset"]=0;	
	tags["/fieldset"]=0;	
	tags["figcaption"]=0;	
	tags["/figcaption"]=0;
	tags["figure"]=0;	
	tags["/figure"]=0;	
	tags["footer"]=0;	
	tags["/footer"]=0;
	tags["form>"]=0;	
	tags["/form>"]=0;
	tags["h1"]=0;	
	tags["/h1"]=0;	
	tags["h6"]=0;	
	tags["/h6"]=0;	
	tags["head"]=0;	
	tags["/head"]=0;	
	tags["header"]=0;	
	tags["/header"]=0;	
	tags["hgroup"]=0;	
	tags["/hgroup"]=0;	
	tags["hr"]=0;	
	tags["/hr"]=0;	
	tags["html"]=0;	
	tags["/html"]=0;	
	tags["i"]=0;	
	tags["/i"]=0;	
	tags["iframe"]=0;	
	tags["/iframe"]=0;	
	tags["img"]=0;	
	tags["/img"]=0;	
	tags["input"]=0;	
	tags["/input"]=0;	
	tags["ins"]=0;	
	tags["/ins"]=0;	
	tags["kbd"]=0;	
	tags["/kbd"]=0;	
	tags["keygen"]=0;	
	tags["/keygen"]=0;	
	tags["label"]=0;	
	tags["/label"]=0;	
	tags["legend"]=0;	
	tags["/legend"]=0;	
	tags["li"]=0;
	tags["/li"]=0;		
	tags["link"]=0;	
	tags["/link"]=0;	
	tags["map"]=0;	
	tags["/map"]=0;	
	tags["mark"]=0;	
	tags["/mark"]=0;	
	tags["menu"]=0;	
	tags["/menu"]=0;	
	tags["meta"]=0;	
	tags["/meta"]=0;	
	tags["meter"]=0;	
	tags["/meter"]=0;	
	tags["nav"]=0;	
	tags["/nav"]=0;	
	tags["noscript"]=0;	
	tags["/noscript"]=0;	
	tags["objet"]=0;	
	tags["/objet"]=0;	
	tags["ol"]=0;	
	tags["/ol"]=0;	
	tags["optgroup"]=0;	
	tags["/optgroup"]=0;	
	tags["option"]=0;	
	tags["/option"]=0;	
	tags["output"]=0;	
	tags["/output"]=0;	
	tags["p"]=0;	
	tags["/p"]=0;
	tags["param"]=0;	
	tags["/param"]=0;
	tags["pre"]=0;	
	tags["/pre"]=0;	
	tags["progress"]=0;	
	tags["/progress"]=0;	
	tags["q"]=0;	
	tags["/q"]=0;	
	tags["rp"]=0;	
	tags["/rp"]=0;	
	tags["rt"]=0;	
	tags["/rt"]=0;	
	tags["ruby"]=0;	
	tags["/ruby"]=0;	
	tags["s"]=0;	
	tags["/s"]=0;
	tags["samp"]=0;	
	tags["/samp"]=0;	
	tags["script"]=0;	
	tags["/script"]=0;	
	tags["section"]=0;	
	tags["/section"]=0;	
	tags["select"]=0;
	tags["/select"]=0;	
	tags["small"]=0;	
	tags["/small"]=0;	
	tags["source"]=0;	
	tags["/source"]=0;	
	tags["span"]=0;	
	tags["/span"]=0;	
	tags["strong"]=0;	
	tags["/strong"]=0;
	tags["style"]=0;	
	tags["/style"]=0;
	tags["sub"]=0;	
	tags["/sub"]=0;	
	tags["summary"]=0;	
	tags["/summary"]=0;	
	tags["sup"]=0;	
	tags["/sup"]=0;	
	tags["table"]=0;	
	tags["/table"]=0;
	tags["tbody"]=0;	
	tags["/tbody"]=0;	
	tags["td"]=0;	
	tags["/td"]=0;	
	tags["textarea"]=0;	
	tags["/textarea"]=0;	
	tags["tfoot"]=0;	
	tags["/tfoot"]=0;	
	tags["th"]=0;	
	tags["/th"]=0;	
	tags["thead"]=0;	
	tags["/thead"]=0;
	tags["time"]=0;	
	tags["/time"]=0;	
	tags["title"]=0;	
	tags["/title"]=0;
	tags["tr"]=0;	
	tags["/tr"]=0;	
	tags["track"]=0;	
	tags["/track"]=0;	
	tags["ul"]=0;	
	tags["/ul"]=0;	
	tags["var"]=0;	
	tags["/var"]=0;
	tags["video"]=0;
	tags["/video"]=0;
	tags["wbr"]=0;
	tags["/wbr"]=0;
	}


	std::map <string,int> mapa::agregarEtiqueta(string token, std::map <string,int> tags){
		iter = tags.find(token);
		if(iter!=tags.end()){
			iter->second++;
			cantidad++;
		}
		return tags;
	}


	void imprimir(std::map <string,int> tags){
		cout<<"*Tags: "<<endl;

		for(iter = tags.begin(); iter!= tags.end(); iter++){
			if(iter->second != 0){
			cout<<"Etiqueta:" <<"<"<< iter->first <<">" <<"  "<<" se encuentra: "<< iter->second << " veces"<<endl;
		}
	}
	}


	void mapa::setMapa(std::map <string,int> newtags){
		this->tags = newtags;
	}


	std::map <string,int> mapa::getMapa(){
		return this->tags;
	}

