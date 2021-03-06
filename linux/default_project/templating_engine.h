std::string program_template_code;
#define _string std::string

char* f(int& argc, char** const& argv){
    std::cout << argv[0] << std::endl; // a

	return argv[2];
}

int preg_template_contents(){
	int yy = 0;
	while ( yy >= 0 ){
		char* ptr;
		int pos = -1;
		int pos2 = -1;

		ptr=strstr((char*)program_template_code.c_str(),"{{");
		pos = ptr - program_template_code.c_str();

		yy	= pos;

		if ( pos < 0 ){
			break;
		}

		

	
		ptr=strstr((char*)program_template_code.c_str(),"}}");
		pos2 = ptr - program_template_code.c_str();
	
		_string ss;
		if ( pos >= 0 ){ 
			for ( int i = pos+2; i < pos2; i++ ){
				ss += program_template_code[i];
				//printf((char*)program_template_code[i]);
			}
		}
	
		char *str = (char*)ss.c_str();
		char *str2 = (char*) malloc ( sizeof (char*) );
		char * pch;
		//printf ("Splitting string \"%s\" into tokens:\n",str);
		pch = strtok (str,".");

		int xx = 0;
		while (pch != NULL)
		{
			str2 = pch;
			pch = strtok (NULL, ".");
			xx++;
		}

		_string testg = data[str][str2];
		program_template_code = program_template_code.replace(pos, (pos2+2)-pos, data[str][str2]);
	}

	printf("\n---\n");
	printf((char*)program_template_code.c_str());
	return 1;
}



#define CHILD_COUNT 20

struct CARROT_ELEMENT{
	CARROT_ELEMENT* PARENT;
	CARROT_ELEMENT* ROOT;
	CARROT_ELEMENT* CHILDREN[CHILD_COUNT];

	int* count;

	std::string* ubr_carrot_id;
	std::string* elementText;
	std::string* ubr_carrot_class;
	std::string* elementType;
	
	std::map<int, std::string>* elemData;
	std::map<int, CARROT_ELEMENT*>* elemData__map_element;
	
	std::map<std::string, std::string>* attr;

	std::map<std::string, std::map<std::string, std::string>*>* CSSClasses;

	std::string* elementCode;
	CARROT_ELEMENT* super (std::string uci = "ubr", std::string ucc = "ubr", std::string _elementType = "div") {
		this->ubr_carrot_id = new std::string();
		this->ubr_carrot_class = new std::string();

		this->elementCode = new std::string();
		this->elementType = new std::string();
		this->elementText = new std::string();
		this->CSSClasses = new std::map<std::string, std::map<std::string, std::string>*>();
		this->attr = new std::map<std::string, std::string>();
		this->elemData = new std::map<int, std::string>();
		this->elemData__map_element = new std::map<int, CARROT_ELEMENT*>();

		*this->elementType = _elementType;
		*this->ubr_carrot_id = uci;
		*this->ubr_carrot_class = ucc;

		count = new int(0);
		*count = this->elemData->size();

		for ( int i = 0; i < CHILD_COUNT; i++ ){
			this->CHILDREN[i] = NULL;
		}
		std::string initCode;
		initCode += "<"+(*this->elementType)+">";
		*this->elementCode = initCode;
		return this;
	}

	CARROT_ELEMENT* init (std::string uci = "ubr", std::string ucc = "ubr", std::string _elementType = "div") {

		this->ubr_carrot_id = new std::string();
		this->ubr_carrot_class = new std::string();
		this->elementCode = new std::string();

		
		
		this->elementType = new std::string();
		this->elementText = new std::string();
		this->attr = new std::map<std::string, std::string>();
		this->elemData = new std::map<int, std::string>();
		this->elemData__map_element = new std::map<int, CARROT_ELEMENT*>();

		*this->elementType = _elementType;
		*this->ubr_carrot_id = uci;
		*this->ubr_carrot_class = ucc;

		count = new int(0);
		*count = this->elemData->size();

		for ( int i = 0; i < CHILD_COUNT; i++ ){
			this->CHILDREN[i] = NULL;
		}
		

		return this;
	}

	CARROT_ELEMENT* addClass(std::string CSSClassName){

		(*this->ubr_carrot_class) += " " + CSSClassName ;

		return this;
	}

	CARROT_ELEMENT* createElement(){
		
		(*this->ROOT->elementCode) += "<" + (*this->elementType) + " id=\"" + (*this->ubr_carrot_id) + "\"" + " class=\"" + (*this->ubr_carrot_class) + "\">";

		return this;
	}


	CARROT_ELEMENT* addChild (std::string ubr_carrot_id = "ubr", std::string ubr_carrot_class = "ubr", std::string _elementType = "div"){
		CARROT_ELEMENT* newCARROT = (CARROT_ELEMENT*)malloc(sizeof(CARROT_ELEMENT*));
		newCARROT->PARENT = this;
		newCARROT->ROOT = this->ROOT;

		//newCARROT->init(ubr_carrot_id.c_str(), ubr_carrot_class.c_str());

		this->CHILDREN[this->elemData->size()] = newCARROT;
		(*this->elemData)[this->elemData->size()] = ubr_carrot_id;
		(*this->elemData__map_element)[this->elemData->size()] = newCARROT;
		*this->count = this->elemData->size();



		return newCARROT;
	
	}

	CARROT_ELEMENT* build(){

		(*this->ROOT->elementCode) += (*this->elementText) + "</" + (*this->elementType) + ">";

		return this;
	}

	CARROT_ELEMENT* rootBuild(){

		(*this->elementCode) += (*this->elementText) + "</" + (*this->elementType) + ">";

		return this;
	}
	
	CARROT_ELEMENT* setText ( std::string _elementText ){
		this->elementText = new std::string(); 
		(*this->elementText) = _elementText;

		return this;
	}
	
	void createCSSClass ( std::string CSSClassName ){
		(*this->CSSClasses)[CSSClassName] = new std::map<std::string,std::string>(); 
	}
	
	void addProp ( std::string CSSClassName, std::string CSSClassProperty, std::string CSSPropertyValue ){
		(*(*this->CSSClasses)[CSSClassName])[CSSClassProperty] = CSSPropertyValue;
	}

	void removeProp ( std::string CSSClassName, std::string CSSClassProperty, std::string CSSPropertyValue ){
		(*(*this->CSSClasses)[CSSClassName])[CSSClassProperty] = "__deleted__" ;
	}

	std::string toHtml(){
		std::string eCode = "";
		eCode += "" + (*this->elementCode);
		return eCode.c_str();
	}
	
};

extern std::map<std::string, std::map<std::string, std::string> > data;

#define MODULE_SERVER 0

	extern std::map<std::string, std::string> getURLPARAMData(std::string _pd = "GET");
	extern bool isSet ( std::string method, std::string value );
	extern std::map<std::string, std::string> _GET;
	extern std::map<std::string, std::string> _POST;
	extern std::map<std::string, std::string> _REQUEST;
	extern std::map<std::string, std::string> _FILE;

int engineTest(){

	getURLPARAMData();
/*
	CARROT_ELEMENT* C_DOM = (CARROT_ELEMENT*)malloc(sizeof(CARROT_ELEMENT*)*50000000);

	C_DOM->super();


	C_DOM->ROOT = C_DOM;
	C_DOM->setText(_GET["username"].c_str());
	(*C_DOM->ROOT->elementType) = "div";

		C_DOM->addChild()->init("mdavis_id", "sdavis_class", "p")->setText(_GET["username"])->createElement()->build();
	

	C_DOM->rootBuild();

	data["data"]["elements"] = C_DOM->toHtml().c_str();//(*C_DOM->elementCode);
	//printf(C_DOM->toHtml().c_str());




	C_DOM->createCSSClass("def_class");
	C_DOM->addProp("def_class", "width", "10px");
*/
	data["data"]["elements"] = _GET["username"];//(*C_DOM->elementCode);
	return 1;
}
