// @@@LICENSE
//
//      Copyright (c) 2010-2012 Hewlett-Packard Development Company, L.P.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// LICENSE@@@

#ifndef SMTPVALIDATIONLISTENER_H_
#define SMTPVALIDATIONLISTENER_H_

#include "core/MojRefCount.h"

class SmtpValidationListener : public MojRefCounted
{
public:

	/**
	 * These match the UI error codes found at:
	 * http://subversion.palm.com/main/nova/palm/luna/apps/email/trunk/app/models/EmailAccountValidation.js
	 */
	typedef enum {
		VALIDATED = 0,
		FAILED_RETRY_RECOMMENDED_KNOWN_ISP = 50,
		FAILED_RETRY_RECOMMENDED = 55,
		BAD_USERNAME_OR_PASSWORD= 100,
		BAD_EMAIL_OR_PASSWORD= 105,
		HOTMAIL_NOT_ENABLED = 500,
		CONNECTION_FAILED = 945,
		HOST_NOT_FOUND = 950,
		TIMED_OUT = 955,
		INTERNAL_ERROR = 960,
		BAD_REQUEST = 965,
		SSL_CONNECTION_ERROR = 970,
		ILLEGAL_PARAMETER = 980,
		NO_NETWORK = 985,
		FAILED = 990,
		ACCOUNT_ALREADY_EXISTS = 995,
		UNKNOWN = 1000
	} ValidationErrorCode;

	virtual ~SmtpValidationListener() { };

	virtual void Success() = 0;
	virtual void Failure(ValidationErrorCode errorCode, std::string errorText) = 0;
};

#endif /* SMTPVALIDATIONLISTENER_H_ */
