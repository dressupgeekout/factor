#include "master.hpp"

#include <sys/types.h>
#include <sys/sysctl.h>

namespace factor {
char *vm_saved_path;

/* From SBCL */
const char *vm_executable_path()
{
  char path[PATH_MAX + 1];

	int size;
	size = readlink("/proc/curproc/file", path, sizeof(path) - 1);
	if (size < 0)
		return NULL;
	path[size] = '\0';

  if(strcmp(path, "unknown") == 0)
    return NULL;

  return safe_strdup(path);
}


}
