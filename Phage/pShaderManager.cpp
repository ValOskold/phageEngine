#include "pShaderManager.h"



pShaderManager::pShaderManager()
{
}


pShaderManager::~pShaderManager()
{
}

pShaderManager::HandleType pShaderManager::createShader(std::string shaderName, std::string vertShaderPath, std::string fragShaderPath, ShaderInfo shaderInfo)
{
	pShaderManager::HandleType result(-1);

	pShader* shdr = new pShader(shaderName, vertShaderPath, fragShaderPath, shaderInfo);
	result =  shaderResources.put(shaderName, shdr);
	return result;
}

pShaderManager::HandleType pShaderManager::addShader(std::string shaderName, pShader * shader)
{
	return shaderResources.put(shaderName, shader);
}

pShader * pShaderManager::getShader(HandleType & handle)
{
	return shaderResources.get(handle);
}

pShader * pShaderManager::getShader(std::string shaderName)
{
	HandleType ref = shaderResources.get(shaderName);
	return shaderResources.get(ref);
}

void pShaderManager::deleteShader(std::string shaderName)
{
	shaderResources.remove(shaderName);
}

void pShaderManager::clear()
{
	shaderResources.clearKeysAndValues();
}
