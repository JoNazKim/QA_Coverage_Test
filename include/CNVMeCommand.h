#ifndef _NVMECOMMAND_H_
#define _NVMECOMMAND_H_

#include "CNVMeCommand.h"
#incldue "QADefine.h"

class CNVMeCommand
{
private:
	CSSD_App	&_ssd = CSSD_App::getInstance();

protected:
	ECODE	_sendSyncCmd(sNVME_CMD &cmd);
	ECODE	_sendAsyncCmd(sNVME_CMD &cmd);
	ECODE	_getResult(uint32 tag, eNVME_CQE &cqe);
public:
	CNVMeCommand();
	~CNVMeCommand();
	
	
	ECODE	identify(sNVME_CDW_IDENTIFY cmd);
	ECODE	getLogPage(sNVME_CDW_GETLOGPAGE cmd);
	ECODE	setFeatures(sNVME_CDW_SETFEATURES cmd);
	ECODE	getFeatures(sNVME_CDW_SETFEATURES cmd);
	
	ECODE	sanitize(sNVME_CDW_SANITIZE cmd);
	
	//...
	
	ECODE	write(sNVME_CDW_IO cmd);
	ECODE	read(sNVME_CDW_IO cmd);
	ECODE	compare(sNVME_CDW_IO cmd);
	ECODE	writeZeroes(sNVME_CDW_IO cmd);
	ECODE	writeUncorrectable(sNVME_CDW_IO cmd);
	ECODE	datasetManagement(sNVME_CDW_IO cmd);
	ECODE	writeUncorrectable(sNVME_CDW_IO cmd);
	
	
};

#endif