
ModelDllps.dll: dlldata.obj ModelDll_p.obj ModelDll_i.obj
	link /dll /out:ModelDllps.dll /def:ModelDllps.def /entry:DllMain dlldata.obj ModelDll_p.obj ModelDll_i.obj \
		kernel32.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \
.c.obj:
	cl /c /Ox /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ModelDllps.dll
	@del ModelDllps.lib
	@del ModelDllps.exp
	@del dlldata.obj
	@del ModelDll_p.obj
	@del ModelDll_i.obj
