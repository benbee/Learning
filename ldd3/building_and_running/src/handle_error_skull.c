int __init my_init_function(void)
{
	int err;

	/* registration takes a pointer and a name */
	err = register_this(ptr1, "skull");
	if (err) goto fail_this;
	err = register_that(ptr2, "skull");
	if (err) goto fail_that;
	err = register_those(ptr3, "skull");
	if (err) goto fail_those;

	return 0;					/* success */

fail_those: unregister_that(ptr2, "skull");
fail_that: unregister_this(ptr1, "skull");
fail_this: return err;			/* propagata the error */
}

void __exit my_cleanup_function(void)
{
	unregister_those(ptr3, "skull");
	unregister_that(ptr2, "skull");
	unregister_this(ptr1, "skull");
	return;
}
