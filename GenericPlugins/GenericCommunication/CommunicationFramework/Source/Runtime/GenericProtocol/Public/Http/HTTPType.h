// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "StaticFunctions/StaticFunctions_Enum.h"
#include "HTTPType.generated.h"

/** 暴露给蓝图的 HTTP 请求状态，镜像 UE IHttpRequest 的处理阶段。 */
UENUM(BlueprintType, DisplayName="HTTP Request Status")
enum class EHttpRequestStatusBP : uint8
{
	/** 请求尚未提交到底层 HTTP 模块，蓝图仍可补充 URL、Header 或内容。 */
	NotStarted UMETA(DisplayName="Not Started"),

	/** 请求已提交并正在传输，异步节点会在进度回调中携带此状态。 */
	Processing UMETA(DisplayName="Processing"),

	/** 底层 HTTP 模块判定请求失败，异步节点会走错误分支。 */
	Failed UMETA(DisplayName="Failed"),

	/** 请求完成且底层状态成功，异步节点会把响应对象交给成功分支。 */
	Succeeded UMETA(DisplayName="Succeeded")
};

/** 将 UE HTTP 状态转换为蓝图枚举，供请求对象和异步节点统一输出。 */
inline EHttpRequestStatusBP ConvertToHttpRequestStatusBP(EHttpRequestStatus::Type HttpRequestStatus)
{
	switch (HttpRequestStatus)
	{
	case EHttpRequestStatus::NotStarted:
		return EHttpRequestStatusBP::NotStarted;
	case EHttpRequestStatus::Processing:
		return EHttpRequestStatusBP::Processing;
	case EHttpRequestStatus::Failed:
		return EHttpRequestStatusBP::Failed;
	/* return EHttpRequestStatusBP::Failed; */
	case EHttpRequestStatus::Succeeded:
		return EHttpRequestStatusBP::Succeeded;
	default: ;
	}

	return EHttpRequestStatusBP::Failed;
}

/** 将蓝图 HTTP 状态转换回 UE 类型，供需要调用底层接口的辅助逻辑复用。 */
inline EHttpRequestStatus::Type ConvertToHttpRequestStatus(EHttpRequestStatusBP HttpRequestStatusBP)
{
	switch (HttpRequestStatusBP)
	{
	case EHttpRequestStatusBP::NotStarted:
		return EHttpRequestStatus::NotStarted;
	case EHttpRequestStatusBP::Processing:
		return EHttpRequestStatus::Processing;
	case EHttpRequestStatusBP::Failed:
		return EHttpRequestStatus::Failed;
	case EHttpRequestStatusBP::Succeeded:
		return EHttpRequestStatus::Succeeded;
	}

	return EHttpRequestStatus::Failed;
}

/** 蓝图可选的 HTTP Verb，发送请求时会转换为底层请求字符串。 */
UENUM(BlueprintType)
enum class EHttpVerb : uint8
{
	/** 读取资源，不携带语义上的写入动作。 */
	GET,

	/** 提交新内容或触发服务端动作，字符串和二进制异步请求会常用它发送正文。 */
	POST,

	/** 以完整资源替换目标地址上的内容。 */
	PUT,

	/** 对目标资源做部分更新。 */
	PATCH,

	/** 只请求响应头，用于探测资源或元数据。 */
	HEAD,

	/** 删除目标资源或让服务端执行删除语义。 */
	DELETE,

	/** 枚举哨兵值，仅用于转换失败或范围保护，不暴露给蓝图选择。 */
	MAX_COUNT UMETA(Hidden)
};

/** 将字符串 Verb 转为蓝图枚举，供响应外部配置或文本输入时复用。 */
inline EHttpVerb ConvertToHttpVerbEnum(const FString& InVerb)
{
	EHttpVerb HttpVerb = EHttpVerb::MAX_COUNT;
	if (FStaticFunctions_Enum::GetEnumByNameString(InVerb, HttpVerb)) { return HttpVerb; }

	return HttpVerb;
}

/** 将蓝图 Verb 转为底层 HTTP 请求需要的字符串。 */
inline FString ConvertToHttpVerbString(const EHttpVerb InVerb) { return FStaticFunctions_Enum::GetEnumNameString(InVerb); }

/** 常用 Content-Type 枚举，SetMimeType 会通过 DisplayName 写入请求头。 */
UENUM(BlueprintType)
enum class EHttpMimeType : uint8
{
	/** Word 旧格式文档的 Content-Type。 */
	doc UMETA(DisplayName="application/msword"),

	/** Word OpenXML 文档的 Content-Type。 */
	docx UMETA(DisplayName="application/vnd.openxmlformats-officedocument.wordprocessingml.document"),

	/** Excel 旧格式表格的 Content-Type。 */
	xls UMETA(DisplayName="application/vnd.ms-excel"),

	/** Excel OpenXML 表格的 Content-Type。 */
	xlsx UMETA(DisplayName="application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"),

	/** PowerPoint 旧格式演示文稿的 Content-Type。 */
	ppt UMETA(DisplayName="application/vnd.ms-powerpoint"),

	/** PowerPoint OpenXML 演示文稿的 Content-Type。 */
	pptx UMETA(DisplayName="application/vnd.openxmlformats-officedocument.presentationml.presentation"),

	/** gzip 压缩包的 Content-Type。 */
	gz UMETA(DisplayName="application/x-gzip"),

	/** zip 压缩包的 Content-Type。 */
	zip UMETA(DisplayName="application/zip"),

	/** rar 压缩包的 Content-Type。 */
	rar UMETA(DisplayName="application/rar"),

	/** tar 归档文件的 Content-Type。 */
	tar UMETA(DisplayName="application/x-tar"),

	/** PDF 文档的 Content-Type。 */
	pdf UMETA(DisplayName="application/pdf"),

	/** RTF 文档的 Content-Type。 */
	rtf UMETA(DisplayName="application/rtf"),

	/** GIF 图片的 Content-Type。 */
	gif UMETA(DisplayName="image/gif"),

	/** JPEG 图片的 Content-Type。 */
	jpg UMETA(DisplayName="image/jpeg"),

	/** JPEG 2000 图片的 Content-Type。 */
	jpg2 UMETA(DisplayName="image/jp2"),

	/** PNG 图片的 Content-Type。 */
	png UMETA(DisplayName="image/png"),

	/** TIFF 图片的 Content-Type。 */
	tiff UMETA(DisplayName="image/tiff"),

	/** BMP 图片的 Content-Type。 */
	bmp UMETA(DisplayName="image/bmp"),

	/** SVG 图片的 Content-Type。 */
	svg UMETA(DisplayName="image/svg+xml"),

	/** WebP 图片的 Content-Type。 */
	webp UMETA(DisplayName="image/webp"),

	/** ICO 图标文件的 Content-Type。 */
	ico UMETA(DisplayName="image/x-icon"),

	/** Photoshop 文档的 Content-Type。 */
	psd UMETA(DisplayName="application/x-photoshop"),

	/** CorelDRAW 文档的 Content-Type。 */
	cdr UMETA(DisplayName="application/x-coreldraw"),

	/** Flash SWF 文件的 Content-Type。 */
	swf UMETA(DisplayName="application/x-shockwave-flash"),

	/** 纯文本请求或响应正文的 Content-Type，ProcessRequest 缺省会使用它。 */
	txt UMETA(DisplayName="text/plain"),

	/** JavaScript 文本的 Content-Type。 */
	js UMETA(DisplayName="text/javascript"),

	/** CSS 文本的 Content-Type。 */
	css UMETA(DisplayName="text/css"),

	/** HTML 文本的 Content-Type。 */
	html UMETA(DisplayName="text/html"),

	/** XHTML 文档的 Content-Type。 */
	xht UMETA(DisplayName="application/xhtml+xml"),

	/** XML 文本的 Content-Type。 */
	xml UMETA(DisplayName="text/xml"),

	/** vCard 联系人文本的 Content-Type。 */
	vcf UMETA(DisplayName="text/x-vcard"),

	/** PHP 脚本文本的 Content-Type。 */
	php UMETA(DisplayName="application/x-httpd-php"),

	/** Java archive 文件的 Content-Type。 */
	jar UMETA(DisplayName="application/java-archive"),

	/** Android 安装包的 Content-Type。 */
	apk UMETA(DisplayName="application/vnd.android.package-archive"),

	/** 通用二进制下载内容的 Content-Type。 */
	exe UMETA(DisplayName="application/octet-stream"),

	/** X.509 证书文件的 Content-Type。 */
	crt UMETA(DisplayName="application/x-x509-user-cert"),

	/** MP3 音频的 Content-Type。 */
	mp3 UMETA(DisplayName="audio/mpeg"),

	/** MIDI 音频的 Content-Type。 */
	mid UMETA(DisplayName="audio/midi"),

	/** WAV 音频的 Content-Type。 */
	wav UMETA(DisplayName="audio/x-wav"),

	/** M3U 播放列表的 Content-Type。 */
	m3u UMETA(DisplayName="audio/x-mpegurl"),

	/** M4A 音频的 Content-Type。 */
	m4a UMETA(DisplayName="audio/x-m4a"),

	/** OGG 音频的 Content-Type。 */
	ogg UMETA(DisplayName="audio/ogg"),

	/** RealAudio 音频的 Content-Type。 */
	ra UMETA(DisplayName="audio/x-realaudio"),

	/** MP4 视频的 Content-Type。 */
	mp4 UMETA(DisplayName="video/mp4"),

	/** MPEG 视频的 Content-Type。 */
	mpeg UMETA(DisplayName="video/mpeg"),

	/** QuickTime MOV 视频的 Content-Type。 */
	mov UMETA(DisplayName="video/quicktime"),

	/** M4V 视频的 Content-Type。 */
	m4v UMETA(DisplayName="video/x-m4v"),

	/** WMV 视频的 Content-Type。 */
	wmv UMETA(DisplayName="video/x-ms-wmv"),

	/** AVI 视频的 Content-Type。 */
	avi UMETA(DisplayName="video/x-msvideo"),

	/** WebM 视频的 Content-Type。 */
	webm UMETA(DisplayName="video/webm"),

	/** FLV 视频的 Content-Type。 */
	flv UMETA(DisplayName="video/x-flv"),

	/** 枚举哨兵值，仅用于转换失败或范围保护，不作为有效 MIME 类型。 */
	MAX_COUNT UMETA(Hidden)
};

/** 返回 MIME 枚举项名称，供字符串配置反查或调试显示。 */
inline FString ConvertToMimeTypeString(EHttpMimeType Type) { return FStaticFunctions_Enum::GetEnumNameString(Type); }

/** 将枚举项名称转换为 MIME 枚举，转换失败时返回 MAX_COUNT。 */
inline EHttpMimeType ConvertToMimeTypeEnum(FString Type)
{
	EHttpMimeType MimeType = EHttpMimeType::MAX_COUNT;
	if (FStaticFunctions_Enum::GetEnumByNameString(Type, MimeType)) { return MimeType; }

	return MimeType;
}

/** 读取枚举 DisplayName 作为实际 Content-Type 头值。 */
inline FString CreateHttpMimeType(EHttpMimeType Type) { return FStaticFunctions_Enum::GetEnumDisplayNameText(Type).ToString(); }

/** 蓝图可比较的 HTTP 响应码集合，异步请求会把整数响应码映射到这里。 */
UENUM(BlueprintType)
enum class EHttpResponseCode : uint8
{
	/** HTTP 100 Continue，客户端可继续发送请求正文。 */
	Code100 UMETA(DisplayName="100 Continue"),

	/** HTTP 101 Switching Protocol，服务端同意协议切换。 */
	Code101 UMETA(DisplayName="101 Switching Protocol"),

	/** HTTP 102 Processing，服务端已收到请求并仍在处理。 */
	Code102 UMETA(DisplayName="102 Processing"),

	/** HTTP 103 Early Hints，服务端提前返回链接提示。 */
	Code103 UMETA(DisplayName="103 Early Hints"),

	/** HTTP 200 OK，请求成功并返回正常响应。 */
	Code200 UMETA(DisplayName="200 OK"),

	/** HTTP 201 Created，请求成功并创建了新资源。 */
	Code201 UMETA(DisplayName="201 Created"),

	/** HTTP 202 Accepted，请求已被接受但尚未完成处理。 */
	Code202 UMETA(DisplayName="202 Accepted"),

	/** HTTP 203 Non-Authoritative Information，返回内容来自非权威来源。 */
	Code203 UMETA(DisplayName="203 Non-Authoritative Information"),

	/** HTTP 204 No Content，请求成功但无正文可读取。 */
	Code204 UMETA(DisplayName="204 No Content"),

	/** HTTP 205 Reset Content，请求成功并要求客户端重置视图。 */
	Code205 UMETA(DisplayName="205 Reset Content"),

	/** HTTP 206 Partial Content，服务端返回范围请求的一部分内容。 */
	Code206 UMETA(DisplayName="206 Partial Content"),

	/** HTTP 207 Multi-Status，响应中包含多个子状态。 */
	Code207 UMETA(DisplayName="207 Multi-Status"),

	/** HTTP 208 Already Reported，DAV 响应中资源已在前文列出。 */
	Code208 UMETA(DisplayName="208 Already Reported"),

	/** HTTP 226 IM Used，服务端返回实例变换后的结果。 */
	Code226 UMETA(DisplayName="226 IM Used"),

	/** HTTP 300 Multiple Choice，目标资源存在多个可选表示。 */
	Code300 UMETA(DisplayName="300 Multiple Choice"),

	/** HTTP 301 Moved Permanently，资源已永久迁移到新地址。 */
	Code301 UMETA(DisplayName="301 Moved Permanently"),

	/** HTTP 302 Found，资源临时位于其他地址。 */
	Code302 UMETA(DisplayName="302 Found"),

	/** HTTP 303 See Other，客户端应使用 GET 访问另一个地址。 */
	Code303 UMETA(DisplayName="303 See Other"),

	/** HTTP 304 Not Modified，缓存内容仍可继续使用。 */
	Code304 UMETA(DisplayName="304 Not Modified"),

	/** HTTP 305 Use Proxy，旧式代理指示响应。 */
	Code305 UMETA(DisplayName="305 Use Proxy"),

	/** HTTP 306 unused，保留状态码，实际响应中不应使用。 */
	Code306 UMETA(DisplayName="306 unused"),

	/** HTTP 307 Temporary Redirect，临时重定向且保留原请求方法。 */
	Code307 UMETA(DisplayName="307 Temporary Redirect"),

	/** HTTP 308 Permanent Redirect，永久重定向且保留原请求方法。 */
	Code308 UMETA(DisplayName="308 Permanent Redirect"),

	/** HTTP 400 Bad Request，请求格式或参数无效。 */
	Code400 UMETA(DisplayName="400 Bad Request"),

	/** HTTP 401 Unauthorized，请求缺少有效认证。 */
	Code401 UMETA(DisplayName="401 Unauthorized"),

	/** HTTP 402 Payment Required，保留的支付相关状态码。 */
	Code402 UMETA(DisplayName="402 Payment Required"),

	/** HTTP 403 Forbidden，服务端拒绝当前访问权限。 */
	Code403 UMETA(DisplayName="403 Forbidden"),

	/** HTTP 404 Not Found，目标资源不存在。 */
	Code404 UMETA(DisplayName="404 Not Found"),

	/** HTTP 405 Method Not Allowed，目标资源不支持当前 Verb。 */
	Code405 UMETA(DisplayName="405 Method Not Allowed"),

	/** HTTP 406 Not Acceptable，服务端无法按 Accept 条件返回内容。 */
	Code406 UMETA(DisplayName="406 Not Acceptable"),

	/** HTTP 407 Proxy Authentication Required，需要代理认证。 */
	Code407 UMETA(DisplayName="407 Proxy Authentication Required"),

	/** HTTP 408 Request Timeout，服务端等待请求超时。 */
	Code408 UMETA(DisplayName="408 Request Timeout"),

	/** HTTP 409 Conflict，请求与当前资源状态冲突。 */
	Code409 UMETA(DisplayName="409 Conflict"),

	/** HTTP 410 Gone，资源已永久移除。 */
	Code410 UMETA(DisplayName="410 Gone"),

	/** HTTP 411 Length Required，请求需要 Content-Length。 */
	Code411 UMETA(DisplayName="411 Length Required"),

	/** HTTP 412 Precondition Failed，请求前置条件不满足。 */
	Code412 UMETA(DisplayName="412 Precondition Failed"),

	/** HTTP 413 Payload Too Large，请求正文超过服务端限制。 */
	Code413 UMETA(DisplayName="413 Payload Too Large"),

	/** HTTP 414 URI Too Long，请求地址过长。 */
	Code414 UMETA(DisplayName="414 URI Too Long"),

	/** HTTP 415 Unsupported Media Type，Content-Type 不受支持。 */
	Code415 UMETA(DisplayName="415 Unsupported Media Type"),

	/** HTTP 416 Range Not Satisfiable，请求范围无法满足。 */
	Code416 UMETA(DisplayName="416 Range Not Satisfiable"),

	/** HTTP 417 Expectation Failed，Expect 条件无法满足。 */
	Code417 UMETA(DisplayName="417 Expectation Failed"),

	/** HTTP 418 I'm a teapot，保留的特殊客户端错误状态。 */
	Code418 UMETA(DisplayName="418 I'm a teapot"),

	/** HTTP 421 Misdirected Request，请求被发送到无法处理该目标的服务端。 */
	Code421 UMETA(DisplayName="421 Misdirected Request"),

	/** HTTP 422 Unprocessable Entity，语义正确但实体内容无法处理。 */
	Code422 UMETA(DisplayName="422 Unprocessable Entity"),

	/** HTTP 423 Locked，目标资源处于锁定状态。 */
	Code423 UMETA(DisplayName="423 Locked"),

	/** HTTP 424 Failed Dependency，请求依赖的前置操作失败。 */
	Code424 UMETA(DisplayName="424 Failed Dependency"),

	/** HTTP 425 Too Early，服务端不愿处理可能被重放的请求。 */
	Code425 UMETA(DisplayName="425 Too Early"),

	/** HTTP 426 Upgrade Required，客户端需要升级协议。 */
	Code426 UMETA(DisplayName="426 Upgrade Required"),

	/** HTTP 428 Precondition Required，服务端要求条件请求。 */
	Code428 UMETA(DisplayName="428 Precondition Required"),

	/** HTTP 429 Too Many Requests，请求频率超过限制。 */
	Code429 UMETA(DisplayName="429 Too Many Requests"),

	/** HTTP 431 Request Header Fields Too Large，请求头过大。 */
	Code431 UMETA(DisplayName="431 Request Header Fields Too Large"),

	/** HTTP 451 Unavailable For Legal Reasons，资源因法律原因不可用。 */
	Code451 UMETA(DisplayName="451 Unavailable For Legal Reasons"),

	/** HTTP 500 Internal Server Error，服务端处理请求时发生内部错误。 */
	Code500 UMETA(DisplayName="500 Internal Server Error"),

	/** HTTP 501 Not Implemented，服务端不支持请求所需功能。 */
	Code501 UMETA(DisplayName="501 Not Implemented"),

	/** HTTP 502 Bad Gateway，网关从上游收到无效响应。 */
	Code502 UMETA(DisplayName="502 Bad Gateway"),

	/** HTTP 503 Service Unavailable，服务暂时不可用。 */
	Code503 UMETA(DisplayName="503 Service Unavailable"),

	/** HTTP 504 Gateway Timeout，网关等待上游响应超时。 */
	Code504 UMETA(DisplayName="504 Gateway Timeout"),

	/** HTTP 505 HTTP Version Not Supported，服务端不支持请求的 HTTP 版本。 */
	Code505 UMETA(DisplayName="505 HTTP Version Not Supported"),

	/** HTTP 506 Variant Also Negotiates，服务端内容协商配置错误。 */
	Code506 UMETA(DisplayName="506 Variant Also Negotiates"),

	/** HTTP 507 Insufficient Storage，服务端存储不足无法完成请求。 */
	Code507 UMETA(DisplayName="507 Insufficient Storage"),

	/** HTTP 508 Loop Detected，服务端检测到循环引用。 */
	Code508 UMETA(DisplayName="508 Loop Detected"),

	/** HTTP 510 Not Extended，请求缺少服务端要求的扩展。 */
	Code510 UMETA(DisplayName="510 Not Extended"),

	/** HTTP 511 Network Authentication Required，需要网络认证。 */
	Code511 UMETA(DisplayName="511 Network Authentication Required"),

	/** 未能映射到已知 HTTP 响应码时使用，异步错误分支也用它表示无响应对象。 */
	CodeUnKnown UMETA(DisplayName="UnKnown Error")
};

/** 将整数响应码转换为蓝图枚举，供异步节点输出稳定的分支数据。 */
inline EHttpResponseCode ConvertToResponseCodeEnum(const int32 InCode)
{
	const FString CodeString = TEXT("Code") + FString::FromInt(InCode);

	EHttpResponseCode Code=EHttpResponseCode::CodeUnKnown;
	if (FStaticFunctions_Enum::GetEnumByNameString(CodeString, Code)) { return Code; }

	return Code;
}

/** 将蓝图响应码还原为整数，CodeUnKnown 返回 -1 表示没有有效 HTTP 状态。 */
inline int32 ConvertToResponseCodeInt(const EHttpResponseCode InCode)
{
	if (InCode == EHttpResponseCode::CodeUnKnown)
	{
		return -1;
	}

	FString CodeString = FStaticFunctions_Enum::GetEnumNameString(InCode);

	CodeString.Split(TEXT("Code"), nullptr, &CodeString, ESearchCase::CaseSensitive);

	return FCString::Atoi(*CodeString);
}
