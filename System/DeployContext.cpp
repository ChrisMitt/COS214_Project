#include "DeployContext.h"

DeployContext::DeployContext( DeployType* d )
{
    this->d = d;
}

DeployContext::~DeployContext()
{
    delete d;
}

void DeployContext::go(){
    d->deploy();
}