/* $Revision: 1.1 $ */
mxArray *FunctionName(mxArray **output_arg1, mxArray *input_arg1,
                      mxArray *input_arg2)
{
    mxArray *local_return_value = NULL;
    mxArray *local_var1 = NULL;
    mxArray *local_var2 = NULL;

    mlfEnterNewContext(1, 2, output_arg1, input_arg1, input_arg2);

    /* Perform the work of the function. */

    /* .... */

    /* Note: Don't destroy local_return_value */
    mxDestroyArray(local_var1);
    mxDestroyArray(local_var2);

    mlfRestorePreviousContext(1, 2, output_arg1, input_arg1, input_arg2);
    return mlfReturnValue(local_return_value);
}
