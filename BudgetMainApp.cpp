#include "BudgetMainApp.h"

bool BudgetMainApp::isUserLoggedIn(){
return userManager.isUserLoggedIn();
}
void BudgetMainApp::registerUser(){
userManager.registerUser();
}
void BudgetMainApp::loginUser(){
userManager.loginUser();
}
void BudgetMainApp::changeUserPassword(){
userManager.changeUserPassword();
}
void BudgetMainApp::logoutUser(){
userManager.loginUser();
}
