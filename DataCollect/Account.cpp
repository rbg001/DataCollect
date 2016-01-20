#include "Account.h"
#include "AccountConfig.pb.h"
#include <io.h>
#include <fstream>
#define ACCOUNT_CONFIG_FILE_NAME "AccountContractConfig.pb"
AccountConfig * Account::ReadAccountConfig(){
	using namespace std;
	

	if (access(ACCOUNT_CONFIG_FILE_NAME, 0) == 0){
		accountConfig = new AccountConfig();
		fstream input(ACCOUNT_CONFIG_FILE_NAME, ios::in | ios::binary);
		accountConfig->ParseFromIstream(&input);
		input.close();
		return accountConfig;
	}
	
	return accountConfig;
}
void Account::SaveAccountConfig(){
	using namespace std;
	try
	{
		fstream out(ACCOUNT_CONFIG_FILE_NAME, ios::out | ios::binary);
		accountConfig->SerializePartialToOstream(&out);
		out.close();
	}
	catch (std::ios_base::failure ee)
	{   
		throw ee;
	}

}
