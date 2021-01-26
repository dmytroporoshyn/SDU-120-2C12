#ifndef __libmwsglm_hpp__
#define __libmwsglm_hpp__ 1

inline void Valign(const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxAlign(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray align(mwVarargout varargout, const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxAlign(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray align(const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxAlign(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Nalign(int nargout, mwVarargout varargout, const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxAlign(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray graphics_private_blt(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_blt(prhs[0], prhs[1]);
}


inline void Vbrighten(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfNBrighten(0, prhs[0], prhs[1]);
}


inline mwArray brighten(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfBrighten(prhs[0], prhs[1]);
}


inline mwArray Nbrighten(int nargout, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfNBrighten(nargout, prhs[0], prhs[1]);
}

inline mwArray bwcontr(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfBwcontr(prhs[0]);
}


inline void camzoom(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfCamzoom(prhs[0], prhs[1]);
}


inline void graphics_private_catpreview(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN)
{
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	mlfGraphics_private_catpreview(prhs[0], prhs[1], prhs[2], prhs[3]);
}


inline void Vcaxis(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfNCaxis(0, NULL, prhs[0], prhs[1]);
}


inline mwArray caxis(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfCaxis(NULL, prhs[0], prhs[1]);
}


inline mwArray caxis(mwArray *out1, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfCaxis(&plhs[1], prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray Ncaxis(int nargout, mwArray *out1, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNCaxis(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, prhs[0], prhs[1]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	return plhs[0];
}

inline void Vgraphics_private_clo(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	mlfNGraphics_private_clo(0, prhs[0], prhs[1], prhs[2]);
}


inline mwArray graphics_private_clo(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_clo(prhs[0], prhs[1], prhs[2]);
}


inline mwArray Ngraphics_private_clo(int nargout, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfNGraphics_private_clo(nargout, prhs[0], prhs[1], prhs[2]);
}

inline void Vclose(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxClose(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray close(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxClose(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray Nclose(int nargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxClose(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline void closereq()
{
	mlfClosereq();
}


inline void clruprop(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfClruprop(prhs[0], prhs[1]);
}


inline void Vcolorbar(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	mlfNColorbar(0, prhs[0], prhs[1], prhs[2]);
}


inline mwArray colorbar(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfColorbar(prhs[0], prhs[1], prhs[2]);
}


inline mwArray Ncolorbar(int nargout, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfNColorbar(nargout, prhs[0], prhs[1], prhs[2]);
}

inline void Vcolordef(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfNColordef(0, prhs[0], prhs[1]);
}


inline mwArray colordef(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfColordef(prhs[0], prhs[1]);
}


inline mwArray Ncolordef(int nargout, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfNColordef(nargout, prhs[0], prhs[1]);
}

inline void Vcolormap(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfNColormap(0, prhs[0], prhs[1]);
}


inline mwArray colormap(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfColormap(prhs[0], prhs[1]);
}


inline mwArray Ncolormap(int nargout, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfNColormap(nargout, prhs[0], prhs[1]);
}

inline void colornone(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfColornone(prhs[0], prhs[1]);
}


inline mwArray colstyle(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfColstyle(NULL, NULL, NULL, prhs[0]);
}


inline mwArray colstyle(mwArray *out1, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfColstyle(&plhs[1], NULL, NULL, prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray colstyle(mwArray *out1, mwArray *out2, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfColstyle(&plhs[1], &plhs[2], NULL, prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray colstyle(mwArray *out1, mwArray *out2, mwArray *out3, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[4];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfColstyle(&plhs[1], &plhs[2], &plhs[3], prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray datachildren(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfDatachildren(prhs[0]);
}


inline mwArray defaultprinter_windows()
{
	return mlfDefaultprinter_windows();
}


inline mwArray dialog(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxDialog(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray graphics_private_disabledberror()
{
	return mlfGraphics_private_disabledberror();
}


inline void graphics_private_enabledberror(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfGraphics_private_enabledberror(prhs[0]);
}


inline void Verrordlg(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxErrordlg(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray errordlg(mwVarargout varargout, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxErrordlg(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray errordlg(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxErrordlg(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Nerrordlg(int nargout, mwVarargout varargout, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxErrordlg(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline void filemenufcn(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfFilemenufcn(prhs[0], prhs[1]);
}


inline mwArray findall(const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxFindall(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray graphics_private_finish(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_finish(prhs[0]);
}


inline void graph2d_private_fixtoolbar(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfGraph2d_private_fixtoolbar(prhs[0]);
}


inline void Viofun_private_fwriteu8(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_fwriteu8(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray iofun_private_fwriteu8(mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_fwriteu8(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray iofun_private_fwriteu8(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_fwriteu8(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Niofun_private_fwriteu8(int nargout, mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_fwriteu8(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray gcbf()
{
	return mlfGcbf();
}


inline void Vgcbo()
{
	mlfNGcbo(0, NULL);
}


inline mwArray gcbo()
{
	return mlfGcbo(NULL);
}


inline mwArray gcbo(mwArray *out1)
{
	MatlabMatrix *plhs[2];
	plhs[0] = mlfGcbo(&plhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray Ngcbo(int nargout, mwArray *out1)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[2];
	plhs[0] = mlfNGcbo(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	return plhs[0];
}

inline mwArray gco(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfGco(prhs[0]);
}


inline mwArray getappdata(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfGetappdata(prhs[0], prhs[1]);
}


inline mwArray graphics_private_getget(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_getget(prhs[0], prhs[1]);
}


inline mwArray getobj(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfGetobj(prhs[0]);
}


inline mwArray graphics_private_getpp(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_getpp(prhs[0]);
}


inline mwArray getuprop(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfGetuprop(prhs[0], prhs[1]);
}


inline mwArray graphics_private_ghostscript(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_ghostscript(prhs[0]);
}


inline void Vginput(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfNGinput(0, NULL, NULL, prhs[0]);
}


inline mwArray ginput(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfGinput(NULL, NULL, prhs[0]);
}


inline mwArray ginput(mwArray *out1, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfGinput(&plhs[1], NULL, prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray ginput(mwArray *out1, mwArray *out2, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfGinput(&plhs[1], &plhs[2], prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray Nginput(int nargout, mwArray *out1, mwArray *out2, const mwArray &in1=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNGinput(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, nargout>2?&plhs[2]:(MatlabMatrix**)NULL, prhs[0]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	  }
	}
	return plhs[0];
}

inline mwArray gpf()
{
	return mlfGpf();
}


inline mwArray gray(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfGray(prhs[0]);
}


inline void Vhdf(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxHdf(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray hdf(mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxHdf(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray hdf(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxHdf(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Nhdf(int nargout, mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxHdf(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline void helpwin(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwVarargin &in4=mwVarargin::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray &in35=mwArray::DIN)
{
	mwVarargin varargin(in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33, in34, in35);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(3 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      varargin.GetArrayBuffer(prhs + 3);
	      nrhs += varargin.Size();
	    }
	  }
	}
	mlxHelpwin(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void Vhgload(const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxHgload(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray hgload(const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxHgload(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray hgload(mwArray *out1, const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxHgload(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray Nhgload(int nargout, mwArray *out1, const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = nargout;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxHgload(nlhs, plhs, nrhs, prhs);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	return plhs[0];
}

inline void hgsave(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxHgsave(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void graphics_private_hpgl(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfGraphics_private_hpgl(prhs[0]);
}


inline mwArray hsv(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfHsv(prhs[0]);
}


inline void Vhsv2rgb(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	mlfNHsv2rgb(0, NULL, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray hsv2rgb(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfHsv2rgb(NULL, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray hsv2rgb(mwArray *out1, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfHsv2rgb(&plhs[1], NULL, prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray hsv2rgb(mwArray *out1, mwArray *out2, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfHsv2rgb(&plhs[1], &plhs[2], prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray Nhsv2rgb(int nargout, mwArray *out1, mwArray *out2, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNHsv2rgb(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, nargout>2?&plhs[2]:(MatlabMatrix**)NULL, prhs[0], prhs[1], prhs[2]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	  }
	}
	return plhs[0];
}

inline void imwrite(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxImwrite(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void Vind2rgb(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfNInd2rgb(0, NULL, NULL, prhs[0], prhs[1]);
}


inline mwArray ind2rgb(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfInd2rgb(NULL, NULL, prhs[0], prhs[1]);
}


inline mwArray ind2rgb(mwArray *out1, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfInd2rgb(&plhs[1], NULL, prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray ind2rgb(mwArray *out1, mwArray *out2, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfInd2rgb(&plhs[1], &plhs[2], prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray Nind2rgb(int nargout, mwArray *out1, mwArray *out2, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNInd2rgb(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, nargout>2?&plhs[2]:(MatlabMatrix**)NULL, prhs[0], prhs[1]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	  }
	}
	return plhs[0];
}

inline mwArray graphics_private_inputcheck(const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxGraphics_private_inputcheck(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray graphics_private_inputcheck(mwArray *out1, const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxGraphics_private_inputcheck(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray graphics_private_inputcheck(mwArray *out1, mwArray *out2, const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[3];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxGraphics_private_inputcheck(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline void Vinputdlg(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN)
{
	MatlabMatrix *prhs[5];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	mlfNInputdlg(0, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4]);
}


inline mwArray inputdlg(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN)
{
	MatlabMatrix *prhs[5];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	return mlfInputdlg(prhs[0], prhs[1], prhs[2], prhs[3], prhs[4]);
}


inline mwArray Ninputdlg(int nargout, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN)
{
	MatlabMatrix *prhs[5];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	return mlfNInputdlg(nargout, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4]);
}

inline mwArray isappdata(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfIsappdata(prhs[0], prhs[1]);
}


inline mwArray general_private_isfigure(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfGeneral_private_isfigure(prhs[0]);
}


inline mwArray graphics_private_isfigure(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_isfigure(prhs[0]);
}


inline mwArray general_private_ishghandle(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfGeneral_private_ishghandle(prhs[0]);
}


inline mwArray graphics_private_ishghandle(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_ishghandle(prhs[0]);
}


inline mwArray graphics_private_isslhandle(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_isslhandle(prhs[0]);
}


inline mwArray jet(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfJet(prhs[0]);
}


inline void Vjpropeditutils(const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxJpropeditutils(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray jpropeditutils(mwVarargout varargout, const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxJpropeditutils(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray jpropeditutils(const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxJpropeditutils(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Njpropeditutils(int nargout, mwVarargout varargout, const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxJpropeditutils(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline void Vlegend(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxLegend(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray legend(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxLegend(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray legend(mwArray *out1, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxLegend(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray Nlegend(int nargout, mwArray *out1, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxLegend(nlhs, plhs, nrhs, prhs);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	return plhs[0];
}

inline mwArray makemenu(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN)
{
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	return mlfMakemenu(prhs[0], prhs[1], prhs[2], prhs[3]);
}


inline void matlabrc()
{
	mlfMatlabrc();
}


inline mwArray menu(const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxMenu(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray menubar()
{
	return mlfMenubar();
}


inline mwArray menulabel(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfMenulabel(NULL, prhs[0]);
}


inline mwArray menulabel(mwArray *out1, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfMenulabel(&plhs[1], prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline void moveaxis(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfMoveaxis(prhs[0]);
}


inline void Vmsgbox(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxMsgbox(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray msgbox(mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxMsgbox(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray msgbox(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxMsgbox(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Nmsgbox(int nargout, mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxMsgbox(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray graphics_private_name(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_name(prhs[0]);
}


inline mwArray graphics_private_newpage(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_newpage(prhs[0]);
}


inline void Vnewplot(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfNNewplot(0, prhs[0]);
}


inline mwArray newplot(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfNewplot(prhs[0]);
}


inline mwArray Nnewplot(int nargout, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfNNewplot(nargout, prhs[0]);
}

inline void Vgraph2d_private_newtext(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxGraph2d_private_newtext(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray graph2d_private_newtext(mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxGraph2d_private_newtext(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray graph2d_private_newtext(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxGraph2d_private_newtext(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Ngraph2d_private_newtext(int nargout, mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxGraph2d_private_newtext(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline void noanimate(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfNoanimate(prhs[0], prhs[1]);
}


inline void nodither(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfNodither(prhs[0], prhs[1]);
}


inline void graphics_private_noselection(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfGraphics_private_noselection(prhs[0], prhs[1]);
}


inline void Vopen(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfNOpen(0, prhs[0]);
}


inline mwArray open(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfOpen(prhs[0]);
}


inline mwArray Nopen(int nargout, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfNOpen(nargout, prhs[0]);
}

inline void Viofun_private_pcxrle(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_pcxrle(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray iofun_private_pcxrle(mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_pcxrle(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray iofun_private_pcxrle(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_pcxrle(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Niofun_private_pcxrle(int nargout, mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_pcxrle(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline void Vplotedit(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPlotedit(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray plotedit(mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPlotedit(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray plotedit(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPlotedit(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Nplotedit(int nargout, mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPlotedit(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline void Viofun_private_png(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_png(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray iofun_private_png(mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_png(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray iofun_private_png(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_png(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Niofun_private_png(int nargout, mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_png(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline void Vpolar(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	mlfNPolar(0, prhs[0], prhs[1], prhs[2]);
}


inline mwArray polar(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfPolar(prhs[0], prhs[1], prhs[2]);
}


inline mwArray Npolar(int nargout, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfNPolar(nargout, prhs[0], prhs[1], prhs[2]);
}

inline mwArray graphics_private_positions(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_positions(prhs[0], prhs[1]);
}


inline mwArray graphics_private_prepare(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_prepare(prhs[0], prhs[1]);
}


inline mwArray graphics_private_preparehg(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_preparehg(prhs[0], prhs[1]);
}


inline mwArray graphics_private_preparepointers(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_preparepointers(prhs[0]);
}


inline mwArray graphics_private_prepareui(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_prepareui(prhs[0], prhs[1]);
}


inline void Vprint(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPrint(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray print(mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPrint(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray print(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPrint(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Nprint(int nargout, mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPrint(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray printdlg(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPrintdlg(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray printjob()
{
	return mlfPrintjob();
}


inline mwArray printopt()
{
	return mlfPrintopt(NULL);
}


inline mwArray printopt(mwArray *out1)
{
	MatlabMatrix *plhs[2];
	plhs[0] = mlfPrintopt(&plhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray printtables(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfPrinttables(NULL, NULL, NULL, NULL, NULL, NULL, prhs[0]);
}


inline mwArray printtables(mwArray *out1, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfPrinttables(&plhs[1], NULL, NULL, NULL, NULL, NULL, prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray printtables(mwArray *out1, mwArray *out2, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfPrinttables(&plhs[1], &plhs[2], NULL, NULL, NULL, NULL, prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray printtables(mwArray *out1, mwArray *out2, mwArray *out3, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[4];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfPrinttables(&plhs[1], &plhs[2], &plhs[3], NULL, NULL, NULL, prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray printtables(mwArray *out1, mwArray *out2, mwArray *out3, mwArray *out4, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[5];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfPrinttables(&plhs[1], &plhs[2], &plhs[3], &plhs[4], NULL, NULL, prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline mwArray printtables(mwArray *out1, mwArray *out2, mwArray *out3, mwArray *out4, mwArray *out5, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[6];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfPrinttables(&plhs[1], &plhs[2], &plhs[3], &plhs[4], &plhs[5], NULL, prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	return plhs[0];
}


inline mwArray printtables(mwArray *out1, mwArray *out2, mwArray *out3, mwArray *out4, mwArray *out5, mwArray *out6, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[7];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfPrinttables(&plhs[1], &plhs[2], &plhs[3], &plhs[4], &plhs[5], &plhs[6], prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	if (out6 != NULL) *out6 = plhs[6];
	return plhs[0];
}


inline mwArray graphics_private_privdos(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxGraphics_private_privdos(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray graphics_private_privdos(mwArray *out1, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxGraphics_private_privdos(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline void graph2d_private_promoteoverlay(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfGraph2d_private_promoteoverlay(prhs[0]);
}


inline void Vpropedit(const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxPropedit(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray propedit(mwVarargout varargout, const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxPropedit(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray propedit(const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxPropedit(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Npropedit(int nargout, mwVarargout varargout, const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxPropedit(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray graphics_private_ptpreparehg(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_ptpreparehg(prhs[0], prhs[1]);
}


inline void graphics_private_ptrestorehg(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfGraphics_private_ptrestorehg(prhs[0], prhs[1]);
}


inline mwArray putdowntext(mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPutdowntext(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray putdowntext(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPutdowntext(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline void Vquestdlg(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN)
{
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	mlfNQuestdlg(0, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
}


inline mwArray questdlg(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN)
{
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	return mlfQuestdlg(prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
}


inline mwArray Nquestdlg(int nargout, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN)
{
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	return mlfNQuestdlg(nargout, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
}

inline mwArray graphics_private_render(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_render(prhs[0], prhs[1]);
}


inline mwArray graphics_private_restore(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_restore(prhs[0], prhs[1]);
}


inline mwArray graphics_private_restorehg(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_restorehg(prhs[0], prhs[1]);
}


inline void graphics_private_restorepointers(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfGraphics_private_restorepointers(prhs[0]);
}


inline mwArray graphics_private_restoreui(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_restoreui(prhs[0], prhs[1]);
}


inline void rotate3d(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfRotate3d(prhs[0], prhs[1]);
}


inline void saveas(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	mlfSaveas(prhs[0], prhs[1], prhs[2]);
}


inline void saveasfig(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfSaveasfig(prhs[0], prhs[1]);
}


inline void saveasm(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfSaveasm(prhs[0], prhs[1]);
}


inline void savtoner(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfSavtoner(prhs[0], prhs[1]);
}


inline mwArray graphics_private_screenpos(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_screenpos(prhs[0], prhs[1]);
}


inline void scribeclearmode(const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxScribeclearmode(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void graphics_private_send(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfGraphics_private_send(prhs[0]);
}


inline void graphics_private_setpp(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfGraphics_private_setpp(prhs[0], prhs[1]);
}


inline void Vsetptr(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxSetptr(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray setptr(mwVarargout varargout, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxSetptr(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray setptr(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxSetptr(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Nsetptr(int nargout, mwVarargout varargout, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxSetptr(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline void graphics_private_setset(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	mlfGraphics_private_setset(prhs[0], prhs[1], prhs[2]);
}


inline mwArray graphics_private_setup(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_setup(prhs[0]);
}


inline void setuprop(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	mlfSetuprop(prhs[0], prhs[1], prhs[2]);
}


inline mwArray graphics_private_start(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_start(prhs[0]);
}


inline void Vstudio(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfNStudio(0, prhs[0]);
}


inline mwArray studio(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfStudio(prhs[0]);
}


inline mwArray Nstudio(int nargout, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfNStudio(nargout, prhs[0]);
}

inline void Vtextwrap(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxTextwrap(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray textwrap(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxTextwrap(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray textwrap(mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1 + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxTextwrap(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs-1, plhs+1);
	return plhs[0];
}


inline mwArray Ntextwrap(int nargout, mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxTextwrap(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs-1, plhs+1);
	return plhs[0];
}

inline mwArray uiclearmode(const mwArray &in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxUiclearmode(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void uiopen(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfUiopen(prhs[0], prhs[1]);
}


inline void uirestore(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfUirestore(prhs[0], prhs[1]);
}


inline void uiresume(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfUiresume(prhs[0]);
}


inline mwArray uisuspend(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfUisuspend(prhs[0]);
}


inline void uiwait(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfUiwait(prhs[0]);
}


inline mwArray graphics_private_validate(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfGraphics_private_validate(prhs[0]);
}


inline void Vwarndlg(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxWarndlg(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray warndlg(mwVarargout varargout, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxWarndlg(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray warndlg(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxWarndlg(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Nwarndlg(int nargout, mwVarargout varargout, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxWarndlg(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline void watchoff(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfWatchoff(prhs[0]);
}


inline mwArray watchon()
{
	return mlfWatchon();
}


inline void whitebg(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfWhitebg(prhs[0], prhs[1]);
}


inline void Viofun_private_wjpgc(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_wjpgc(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray iofun_private_wjpgc(mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_wjpgc(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray iofun_private_wjpgc(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_wjpgc(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Niofun_private_wjpgc(int nargout, mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_wjpgc(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline void iofun_private_writebmp(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwVarargin &in4=mwVarargin::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray &in35=mwArray::DIN)
{
	mwVarargin varargin(in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33, in34, in35);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(3 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      varargin.GetArrayBuffer(prhs + 3);
	      nrhs += varargin.Size();
	    }
	  }
	}
	mlxIofun_private_writebmp(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void iofun_private_writehdf(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwVarargin &in4=mwVarargin::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray &in35=mwArray::DIN)
{
	mwVarargin varargin(in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33, in34, in35);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(3 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      varargin.GetArrayBuffer(prhs + 3);
	      nrhs += varargin.Size();
	    }
	  }
	}
	mlxIofun_private_writehdf(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void iofun_private_writejpg(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwVarargin &in4=mwVarargin::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray &in35=mwArray::DIN)
{
	mwVarargin varargin(in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33, in34, in35);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(3 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      varargin.GetArrayBuffer(prhs + 3);
	      nrhs += varargin.Size();
	    }
	  }
	}
	mlxIofun_private_writejpg(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void iofun_private_writepcx(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwVarargin &in4=mwVarargin::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray &in35=mwArray::DIN)
{
	mwVarargin varargin(in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33, in34, in35);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(3 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      varargin.GetArrayBuffer(prhs + 3);
	      nrhs += varargin.Size();
	    }
	  }
	}
	mlxIofun_private_writepcx(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void iofun_private_writepng(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwVarargin &in4=mwVarargin::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray &in35=mwArray::DIN)
{
	mwVarargin varargin(in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33, in34, in35);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(3 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      varargin.GetArrayBuffer(prhs + 3);
	      nrhs += varargin.Size();
	    }
	  }
	}
	mlxIofun_private_writepng(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void iofun_private_writetif(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwVarargin &in4=mwVarargin::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray &in35=mwArray::DIN)
{
	mwVarargin varargin(in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33, in34, in35);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(3 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      varargin.GetArrayBuffer(prhs + 3);
	      nrhs += varargin.Size();
	    }
	  }
	}
	mlxIofun_private_writetif(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void iofun_private_writexwd(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwVarargin &in4=mwVarargin::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray &in35=mwArray::DIN)
{
	mwVarargin varargin(in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33, in34, in35);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(3 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      varargin.GetArrayBuffer(prhs + 3);
	      nrhs += varargin.Size();
	    }
	  }
	}
	mlxIofun_private_writexwd(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void Viofun_private_wtifc(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_wtifc(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray iofun_private_wtifc(mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_wtifc(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray iofun_private_wtifc(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_wtifc(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Niofun_private_wtifc(int nargout, mwVarargout varargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIofun_private_wtifc(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline void Vzoom(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxZoom(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray zoom(const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxZoom(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray Nzoom(int nargout, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxZoom(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

#endif /* __libmwsglm_hpp__ */
