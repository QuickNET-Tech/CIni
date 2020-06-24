#pragma once

class CIni {
public:
	explicit CIni(const std::string& file) {
		iniFile = file;
	}

	/* --------------- SET --------------- */

	bool setString(const std::string& string, const std::string& app, const std::string& key) {
		try {
			WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), iniFile.c_str());
			return true;
		}
		catch(...) {
			return false;
		}
	}

	bool setInt32(int value, const std::string& app, const std::string& key) {
		try {
			setString(std::to_string(value), app, key);
			return true;
		}
		catch(...) {
			return false;
		}
	}

	bool setUint32(uint32_t value, const std::string& app, const std::string& key) {
		try {
			setString(std::to_string(value), app, key);
			return true;
		}
		catch(...) {
			return false;
		}
	}

	bool setInt64(int64_t value, const std::string& app, const std::string& key) {
		try {
			setString(std::to_string(value), app, key);
			return true;
		}
		catch(...) {
			return false;
		}
	}

	bool setUint64(uint64_t value, const std::string& app, const std::string& key) {
		try {
			setString(std::to_string(value), app, key);
			return true;
		}
		catch(...) {
			return false;
		}
	}

	bool setFloat(float value, const std::string& app, const std::string& key) {
		try {
			setString(std::to_string(value), app, key);
			return true;
		}
		catch(...) {
			return false;
		}
	}

	bool setBool(bool value, const std::string& app, const std::string& key) {
		try {
			setString((value ? "1" : "0"), app, key);
			return true;
		}
		catch(...) {
			return false;
		}
	}

	/* --------------- GET --------------- */

	// On failure, if write on fail is true, failvalue will be written at the specified app and key.
	// After that failValue will be returned, even if it wasn't written.
	std::string getString(const std::string& app, const std::string& key, const std::string& failValue, bool writeOnFail) {
		try {
			char buf[100];
			GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, iniFile.c_str());
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
	int getInt32(const std::string& app, const std::string& key, int failValue, bool writeOnFail) {
		try {
			char buf[100];
			GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, iniFile.c_str());
			return std::stoi(buf);
		}
		catch(...) {
			if(writeOnFail) {
				setInt32(failValue, app, key);
			}
			return failValue;
		}
	}

	// On failure, if write on fail is true, failvalue will be written at the specified app and key.
	// After that failValue will be returned, even if it wasn't written.
	uint32_t getUint32(const std::string& app, const std::string& key, int failValue, bool writeOnFail) {
		try {
			char buf[100];
			GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, iniFile.c_str());
			return std::strtoul(buf, nullptr, 0);
		}
		catch(...) {
			if(writeOnFail) {
				setUint32(failValue, app, key);
			}
			return failValue;
		}
	}

	// On failure, if write on fail is true, failvalue will be written at the specified app and key.
	// After that failValue will be returned, even if it wasn't written.
	int64_t getInt64(const std::string& app, const std::string& key, int failValue, bool writeOnFail) {
		try {
			char buf[100];
			GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, iniFile.c_str());
			return std::stoll(buf);
		}
		catch(...) {
			if(writeOnFail) {
				setInt64(failValue, app, key);
			}
			return failValue;
		}
	}

	// On failure, if write on fail is true, failvalue will be written at the specified app and key.
	// After that failValue will be returned, even if it wasn't written.
	uint64_t getUint64(const std::string& app, const std::string& key, int failValue, bool writeOnFail) {
		try {
			char buf[100];
			GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, iniFile.c_str());
			return std::stoull(buf);
		}
		catch(...) {
			if(writeOnFail) {
				setUint64(failValue, app, key);
			}
			return failValue;
		}
	}

	// On failure, if write on fail is true, failvalue will be written at the specified app and key.
	// After that failValue will be returned, even if it wasn't written.
	float getFloat(const std::string& app, const std::string& key, float failValue, bool writeOnFail) {
		try {
			char buf[100];
			GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, iniFile.c_str());
			return std::stof(buf);
		}
		catch(...) {
			if(writeOnFail) {
				setFloat(failValue, app, key);
			}
			return failValue;
		}
	}

	// On failure, if write on fail is true, failvalue will be written at the specified app and key.
	// After that failValue will be returned, even if it wasn't written.
	bool getBool(const std::string& app, const std::string& key, bool failValue, bool writeOnFail) {
		try {
			char buf[100];
			GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, iniFile.c_str());
			return (std::stoi(buf) ? true : false);
		}
		catch(...) {
			if(writeOnFail) {
				setBool(failValue, app, key);
			}
			return failValue;
		}
	}

	/* --------------- UNSAFE GET ---------------*/

	// No error handling, only use if you plan to handle errors on your own
	std::string getStringUnsafe(const std::string& app, const std::string& key) {
		char buf[100];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, iniFile.c_str());
		return buf;
	}

	// No error handling, only use if you plan to handle errors on your own
	int getInt32Unsafe(const std::string& app, const std::string& key) {
		char buf[100];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, iniFile.c_str());
		return std::stoi(buf);
	}

	// No error handling, only use if you plan to handle errors on your own
	uint32_t getUint32Unsafe(const std::string& app, const std::string& key) {
		char buf[100];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, iniFile.c_str());
		return std::strtoul(buf, nullptr, 0);
	}

	// No error handling, only use if you plan to handle errors on your own
	int64_t getInt64Unsafe(const std::string& app, const std::string& key) {
		char buf[100];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, iniFile.c_str());
		return std::stoll(buf);
	}

	// No error handling, only use if you plan to handle errors on your own
	uint64_t getUint64Unsafe(const std::string& app, const std::string& key) {
		char buf[100];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, iniFile.c_str());
		return std::stoull(buf);
	}

	// No error handling, only use if you plan to handle errors on your own
	float getFloatUnsafe(const std::string& app, const std::string& key) {
		char buf[100];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, iniFile.c_str());
		return std::stof(buf);
	}

	// No error handling, only use if you plan to handle errors on your own
	bool getBoolUnsafe(const std::string& app, const std::string& key) {
		char buf[100];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, iniFile.c_str());
		return (std::stoi(buf) ? true : false);
	}

private:
	std::string iniFile;
};
