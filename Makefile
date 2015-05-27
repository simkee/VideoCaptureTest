.PHONY: clean All

All:
	@echo "----------Building project:[ VideoCaptureTest - Debug ]----------"
	@cd "src" && $(MAKE) -f  "VideoCaptureTest.mk"
clean:
	@echo "----------Cleaning project:[ VideoCaptureTest - Debug ]----------"
	@cd "src" && $(MAKE) -f  "VideoCaptureTest.mk" clean
