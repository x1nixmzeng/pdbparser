#include "pdbparser/pdb_file.h"

// demo to dump any function names

int main(int argc, char** argv)
{
	using namespace pdbparser;

	PDBFile pdb;

	if (argc > 1)
	{
		PDBFileState state = pdb.load_pdb_file(argv[1]);

		if (state != PDBFileState::PDB_STATE_OK)
			return 1;

		int virtual_base_addr = 0;
		pdb.initialize(virtual_base_addr);

		if (PDBFunctionAddressMap* functionMap = pdb.get_functions())
		{
			printf("%i functions\n\n", functionMap->size());

			for (const auto& func : *functionMap)
			{
				printf("F %s\n", func.second->name);
			}
		}
	}

	return 0;
}
