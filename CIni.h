#pragma once

#ifndef CINI_BUFFER_SIZE
#define CINI_BUFFER_SIZE 0xFF
#endif


class CIni {
public:
	explicit CIni(const std::string& file) : iniFile(file.data()) {}
	explicit CIni(const char* file) : iniFile(file) {}

	/* --------------- SET --------------- */

	bool setString(const char* string, const char* app, const char* key) const {
		try {
			WritePrivateProfileStringA(app, key, string, iniFile);
			return true;
		}
		catch(...) {
			return false;
		}
	}

	bool setInt32(const int32_t value, const std::string& app, const std::string& key) const {
		return setString(std::to_string(value).data(), app.data(), key.data());
	}

	bool setInt32(const int32_t value, const char* app, const char* key) const {
		return setString(std::to_string(value).data(), app, key);
	}

	bool setUint32(const uint32_t value, const std::string& app, const std::string& key) const {
		return setString(std::to_string(value).data(), app.data(), key.data());
	}

	bool setUint32(const uint32_t value, const char* app, const char* key) const {
		return setString(std::to_string(value).data(), app, key);
	}

	bool setInt64(const int64_t value, const std::string& app, const std::string& key) const {
		return setString(std::to_string(value).data(), app.data(), key.data());
	}

	bool setInt64(const int64_t value, const char* app, const char* key) const {
		return setString(std::to_string(value).data(), app, key);
	}

	bool setUint64(const uint64_t value, const std::string& app, const std::string& key) const {
		return setString(std::to_string(value).data(), app.data(), key.data());
	}

	bool setUint64(const uint64_t value, const char* app, const char* key) const {
		return setString(std::to_string(value).data(), app, key);
	}

	bool setFloat(const float value, const std::string& app, const std::string& key) const {
		return setString(std::to_string(value).data(), app.data(), key.data());
	}

	bool setFloat(const float value, const char* app, const char* key) const {
		return setString(std::to_string(value).data(), app, key);
	}

	bool setBool(const bool value, const std::string& app, const std::string& key) const {
		return setString(std::to_string(value).data(), app.data(), key.data());
	}

	bool setBool(const bool value, const char* app, const char* key) const {
		return setString(std::to_string(value).data(), app, key);
	}

	/* --------------- GET --------------- */

	// On failure, if write on fail is true, failvalue will be written at the specified app and key.
	// After that failValue will be returned, even if it wasn't written.
	std::string getString(const char* app, const char* key, const char* failValue, const bool writeOnFail, const uint16_t bufferSize = 0xFF) const {
		try {
			char buf[CINI_BUFFER_SIZE];
			GetPrivateProfileStringA(app, key, "NULL", buf, sizeof(buf), iniFile);
			return buf;
		}
		catch(...) {
			if(writeOnFail) {
				setString(failValue, app, key);
			}
			return failValue;
		}
	}

	// On failure, if write on fail is true, failvalue will be written at the specified app and key.
	// After that failValue will be returned, even if it wasn't written.
	int getInt32(const std::string& app, const std::string& key, int failValue, const bool writeOnFail) const {
		return std::stoi(getString(app.data(), key.data(), std::to_string(failValue).data(), writeOnFail));
	}

	// On failure, if write on fail is true, failvalue will be written at the specified app and key.
	// After that failValue will be returned, even if it wasn't written.
	int getInt32(const char* app, const char* key, int failValue, const bool writeOnFail) const {
		return std::stoi(getString(app, key, std::to_string(failValue).data(), writeOnFail));
	}

	// On failure, if write on fail is true, failvalue will be written at the specified app and key.
	// After that failValue will be returned, even if it wasn't written.
	uint32_t getUint32(const std::string& app, const std::string& key, const int failValue, const bool writeOnFail) const {
		return std::strtoul(getString(app.data(), key.data(), std::to_string(failValue).data(), writeOnFail).data(), nullptr, 0);
	}

	// On failure, if write on fail is true, failvalue will be written at the specified app and key.
	// After that failValue will be returned, even if it wasn't written.
	uint32_t getUint32(const char* app, const char* key, const int failValue, const bool writeOnFail) const {
		return std::strtoul(getString(app, key, std::to_string(failValue).data(), writeOnFail).data(), nullptr, 0);
	}

	// On failure, if write on fail is true, failvalue will be written at the specified app and key.
	// After that failValue will be returned, even if it wasn't written.
	int64_t getInt64(const std::string& app, const std::string& key, const int failValue, const bool writeOnFail) const {
		return std::stoll(getString(app.data(), key.data(), std::to_string(failValue).data(), writeOnFail));
	}

	// On failure, if write on fail is true, failvalue will be written at the specified app and key.
	// After that failValue will be returned, even if it wasn't written.
	int64_t getInt64(const char* app, const char* key, const int failValue, const bool writeOnFail) const {
		return std::stoll(getString(app, key, std::to_string(failValue).data(), writeOnFail));
	}

	// On failure, if write on fail is true, failvalue will be written at the specified app and key.
	// After that failValue will be returned, even if it wasn't written.
	uint64_t getUint64(const std::string& app, const std::string& key, const int failValue, const bool writeOnFail) const {
		return std::stoull(getString(app.data(), key.data(), std::to_string(failValue).data(), writeOnFail));
	}

	// On failure, if write on fail is true, failvalue will be written at the specified app and key.
	// After that failValue will be returned, even if it wasn't written.
	uint64_t getUint64(const char* app, const char* key, const int failValue, const bool writeOnFail) const {
		return std::stoull(getString(app, key, std::to_string(failValue).data(), writeOnFail));
	}

	// On failure, if write on fail is true, failvalue will be written at the specified app and key.
	// After that failValue will be returned, even if it wasn't written.
	float getFloat(const std::string& app, const std::string& key, const float failValue, const bool writeOnFail) const {
		return std::stof(getString(app.data(), key.data(), std::to_string(failValue).data(), writeOnFail));
	}

	// On failure, if write on fail is true, failvalue will be written at the specified app and key.
	// After that failValue will be returned, even if it wasn't written.
	float getFloat(const char* app, const char* key, const float failValue, const bool writeOnFail) const {
		return std::stof(getString(app, key, std::to_string(failValue).data(), writeOnFail));
	}

	// On failure, if write on fail is true, failvalue will be written at the specified app and key.
	// After that failValue will be returned, even if it wasn't written.
	bool getBool(const std::string& app, const std::string& key, const bool failValue, const bool writeOnFail) const {
		return (std::stoi(getString(app.data(), key.data(), std::to_string(failValue).data(), writeOnFail)) ? true : false);
	}

	// On failure, if write on fail is true, failvalue will be written at the specified app and key.
	// After that failValue will be returned, even if it wasn't written.
	bool getBool(const char* app, const char* key, const bool failValue, const bool writeOnFail) const {
		return (std::stoi(getString(app, key, std::to_string(failValue).data(), writeOnFail)) ? true : false);
	}

	/* --------------- UNSAFE GET ---------------*/

	// No error handling, only use if you plan to handle errors on your own
	std::string getStringUnsafe(const std::string& app, const std::string& key) const {
		char buf[CINI_BUFFER_SIZE];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, sizeof(buf), iniFile);
		return buf;
	}

	// No error handling, only use if you plan to handle errors on your own
	int getInt32Unsafe(const std::string& app, const std::string& key) const {
		char buf[CINI_BUFFER_SIZE];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, sizeof(buf), iniFile);
		return std::stoi(buf);
	}

	// No error handling, only use if you plan to handle errors on your own
	uint32_t getUint32Unsafe(const std::string& app, const std::string& key) const {
		char buf[CINI_BUFFER_SIZE];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, sizeof(buf), iniFile);
		return std::strtoul(buf, nullptr, 0);
	}

	// No error handling, only use if you plan to handle errors on your own
	int64_t getInt64Unsafe(const std::string& app, const std::string& key) const {
		char buf[CINI_BUFFER_SIZE];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, sizeof(buf), iniFile);
		return std::stoll(buf);
	}

	// No error handling, only use if you plan to handle errors on your own
	uint64_t getUint64Unsafe(const std::string& app, const std::string& key) const {
		char buf[CINI_BUFFER_SIZE];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, sizeof(buf), iniFile);
		return std::stoull(buf);
	}

	// No error handling, only use if you plan to handle errors on your own
	float getFloatUnsafe(const std::string& app, const std::string& key) const {
		char buf[CINI_BUFFER_SIZE];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, sizeof(buf), iniFile);
		return std::stof(buf);
	}

	// No error handling, only use if you plan to handle errors on your own
	bool getBoolUnsafe(const std::string& app, const std::string& key) const {
		char buf[CINI_BUFFER_SIZE];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, sizeof(buf), iniFile);
		return (std::stoi(buf) ? true : false);
	}

private:
	const char* iniFile; // maybe this :eyes:
};
