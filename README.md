# Win_Hash-CheckMaster
A program for checking if Hashcodes and files are matched or not, and allowed to check multiple files in one time.

用于同时检测多个文件哈希值的程序

Still in developing (now working on UI)

TIPS: 
When you use it in practice, please remember a MD5-confirmed file doesn't absolutely mean a confirmed file.Since MD5 has only 16^32 possibilities, it's likely to be two different files that have the same MD5 and some network disk may download a MD5-confirmed file instead of a confirmed file,which may also cause a wrong result.

注意：
实际应用中，请注意MD5正确并不代表文件正确。 MD5值共有16^32种可能性，所以很可能存在两个不同的文件有着相同的MD5值。同时，有的云盘服务商可能会下载MD5正确的文件而不是你所要下载的正确文件，也可能导致MD5值相同但文件不同。
