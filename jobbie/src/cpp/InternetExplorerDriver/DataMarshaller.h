#ifndef JOBBIE_DATAMARSHALLER_H_
#define JOBBIE_DATAMARSHALLER_H_

#include <mshtml.h>
#include <vector>

using namespace std;

class EventHandler
{
private:
	HANDLE				sync;
public:
	EventHandler(void);
	~EventHandler(void);
	operator HANDLE() const {return sync;}
};

class DataMarshaller
{
public:
	DataMarshaller(void);

	// WARNING can only be set by calling thread. Do not copy or reference these variables
	// use them only from this class in place.
	LPCWSTR			input_string_;
	long			input_long_;
	IHTMLElement	*input_html_element_;
	SAFEARRAY		*input_safe_array_;

	// WARNING can only be set by worker thread
	std::wstring	output_string_;
	long			output_long_;
	bool			output_bool_;
	IHTMLElement	*output_html_element_;
	std::vector<IHTMLElement*> output_list_html_element_;
	CComVariant		output_variant_;

	EventHandler	synchronization_flag_;

public:

	void resetInputs();
	void resetOutputs();
};

#endif // JOBBIE_DATAMARSHALLER_H_
