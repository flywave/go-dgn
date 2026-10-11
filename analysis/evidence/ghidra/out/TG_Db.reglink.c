/* ==== 1800548f0 FUN_1800548f0 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1800548f0(void)

{
  longlong *plVar1;
  OdRxDictionary *pOVar2;
  OdDgnClassMap *pOVar3;
  OdRxClass *pOVar4;
  OdRxClass *pOVar5;
  int *piVar6;
  longlong *local_res10;
  longlong *local_res18;
  OdString local_res20 [8];
  
  odDbRootInitialize();
  odgiInitialize();
  OdDgHostAppServices::rxInit();
  OdDgRxEvent::rxInit();
  OdDgEditor::rxInit();
  OdDgRxEventImpl::rxInit();
  OdDgEditorImpl::rxInit();
  plVar1 = (longlong *)OdDgEditorImpl::createObject();
  plVar1 = (longlong *)*plVar1;
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x20))(plVar1);
  }
  if (local_res10 != (longlong *)0x0) {
    (**(code **)(*local_res10 + 0x28))();
  }
  pOVar2 = odrxSysRegistry();
  OdString::OdString(local_res20,(ushort *)L"OdDgEditor");
  (**(code **)(*(longlong *)pOVar2 + 0x78))(pOVar2,&local_res18,local_res20,plVar1,0);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
    local_res18 = (longlong *)0x0;
  }
  OdString::~OdString(local_res20);
  OdString::OdString(local_res20,(ushort *)L"OdDgRxEvent");
  (**(code **)(*(longlong *)pOVar2 + 0x78))(pOVar2,&local_res18,local_res20,plVar1,0);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
    local_res18 = (longlong *)0x0;
  }
  OdString::~OdString(local_res20);
  OdDgExtraElementCustomizationServices::rxInit();
  OdDgExtraElementCustomizationServices::registerExtraElementCustomizationServices();
  OdDgElement::rxInit();
  OdDgGraphicsElement::rxInit();
  OdDgCurveElement2d::rxInit();
  OdDgCurveElement3d::rxInit();
  OdDgMultiVertex2d::rxInit();
  OdDgMultiVertex3d::rxInit();
  OdDgCellHeader2d::rxInit();
  OdDgCellHeader3d::rxInit();
  OdDgAnnotationCellHeader2d::rxInit();
  OdDgAnnotationCellHeader3d::rxInit();
  OdDgAssocRegion2d::rxInit();
  OdDgAssocRegion3d::rxInit();
  OdDgLine2d::rxInit();
  OdDgLine3d::rxInit();
  OdDgLineString2d::rxInit();
  OdDgLineString3d::rxInit();
  OdDgColorTable::rxInit();
  OdDgShape2d::rxInit();
  OdDgShape3d::rxInit();
  OdDgTextNode2d::rxInit();
  OdDgTextNode3d::rxInit();
  OdDgDesignFileHeader::rxInit();
  OdDgCurve2d::rxInit();
  OdDgCurve3d::rxInit();
  OdDgComplexCurve::rxInit();
  OdDgComplexString::rxInit();
  OdDgConic2d::rxInit();
  OdDgConic3d::rxInit();
  OdDgComplexShape::rxInit();
  OdDgRasterFrame::rxInit();
  OdDgEllipse2d::rxInit();
  OdDgEllipse3d::rxInit();
  OdDgArc2d::rxInit();
  OdDgArc3d::rxInit();
  OdDgText2d::rxInit();
  OdDgText3d::rxInit();
  OdDgSurface::rxInit();
  OdDgSolid::rxInit();
  OdDgBSplinePoles2d::rxInit();
  OdDgBSplinePoles3d::rxInit();
  OdDgPointString2d::rxInit();
  OdDgPointString3d::rxInit();
  OdDgCone::rxInit();
  OdDgBSplineSurface::rxInit();
  OdDgBSplineBoundary::rxInit();
  OdDgBSplineKnots::rxInit();
  OdDgBSplineCurve2d::rxInit();
  OdDgBSplineCurve3d::rxInit();
  OdDgBSplineWeights::rxInit();
  OdDgDimension::rxInit();
  OdDgDimSizeArrow::rxInit();
  OdDgDimSizeStroke::rxInit();
  OdDgDimSingleLocation::rxInit();
  OdDgDimStackedLocation::rxInit();
  OdDgDimAngleSize::rxInit();
  OdDgDimArcSize::rxInit();
  OdDgDimAngleLocation::rxInit();
  OdDgDimArcLocation::rxInit();
  OdDgDimAngleLines::rxInit();
  OdDgDimRadius::rxInit();
  OdDgDimRadiusExtended::rxInit();
  OdDgDimDiameter::rxInit();
  OdDgDimDiameterExtended::rxInit();
  OdDgDimDiameterParallel::rxInit();
  OdDgDimDiameterPerpendicular::rxInit();
  OdDgDimCustomLinear::rxInit();
  OdDgDimOrdinate::rxInit();
  OdDgDimCenter::rxInit();
  OdDgDimAngleAxisX::rxInit();
  OdDgDimAngleAxisY::rxInit();
  OdDgDimNote::rxInit();
  OdDgDimLabelLine::rxInit();
  OdDgSharedCellDefinition::rxInit();
  OdDgSharedCellReference::rxInit();
  OdDgMultiline::rxInit();
  OdDgTagElement::rxInit();
  OdDgDgnStoreComponent::rxInit();
  OdDgTagDefinitionSet::rxInit();
  OdDgItemTypeLibrary::rxInit();
  OdDgXMLSchemaContainer::rxInit();
  OdDgApplicationData::rxInit();
  OdDgElementTemplate::rxInit();
  OdDgLinkSet::rxInit();
  OdDgColorBook::rxInit();
  OdDgElementIdPath::rxInit();
  OdDgItemType::rxInit();
  OdDgItemTypeProperty::rxInit();
  OdDgXMLCustomSchemaContainer::rxInit();
  OdDgCustomItemType::rxInit();
  OdDgCustomItemTypeProperty::rxInit();
  OdDgPrintStyleTableRecord::rxInit();
  OdDgGeoDataInfo::rxInit();
  OdDgGeoDataCoordinateSystemCategory::rxInit();
  OdDgGeoDataReprojectionCoordinateTransformer::rxInit();
  OdDgGeoDataCoordinateConverter::rxInit();
  OdDgGeoDataCoordinateSystem::rxInit();
  OdDgGeographicCoordinateSystem::rxInit();
  OdDgTransverseMercatorCoordinateSystem::rxInit();
  OdDgAlbersEqualAreaConicCoordinateSystem::rxInit();
  OdDgMercatorCoordinateSystem::rxInit();
  OdDgLambertAzimuthalEquidistantCoordinateSystem::rxInit();
  OdDgLambertTangentialCoordinateSystem::rxInit();
  OdDgPolyconicCoordinateSystem::rxInit();
  OdDgPolyconicModCoordinateSystem::rxInit();
  OdDgAzimuthalEqualAreaCoordinateSystem::rxInit();
  OdDgEquidistantConicCoordinateSystem::rxInit();
  OdDgMillerCoordinateSystem::rxInit();
  OdDgStereographicModCoordinateSystem::rxInit();
  OdDgNewZealandCoordinateSystem::rxInit();
  OdDgSinusoidalCoordinateSystem::rxInit();
  OdDgOrthographicCoordinateSystem::rxInit();
  OdDgGnomonicCoordinateSystem::rxInit();
  OdDgEquidistantCylindricalCoordinateSystem::rxInit();
  OdDgVanDerGrintenCoordinateSystem::rxInit();
  OdDgCassiniCoordinateSystem::rxInit();
  OdDgRobinsonCoordinateSystem::rxInit();
  OdDgBonneCoordinateSystem::rxInit();
  OdDgEckert4CoordinateSystem::rxInit();
  OdDgEckert6CoordinateSystem::rxInit();
  OdDgMollweideCoordinateSystem::rxInit();
  OdDgGoodeHomolosineCoordinateSystem::rxInit();
  OdDgEqualAreaCylindricalNACoordinateSystem::rxInit();
  OdDgEqualAreaCylindricalTACoordinateSystem::rxInit();
  OdDgBipolarObliqueConformalConicCoordinateSystem::rxInit();
  OdDgSwissObliqueCylindricalCoordinateSystem::rxInit();
  OdDgPolarStereographicCoordinateSystem::rxInit();
  OdDgObliqueStereographicCoordinateSystem::rxInit();
  OdDgSnyderObliqueStereographicCoordinateSystem::rxInit();
  OdDgLambertConformalConic1StdLatCoordinateSystem::rxInit();
  OdDgLambertConformalConicCoordinateSystem::rxInit();
  OdDgLambertConformalConicMichiganCoordinateSystem::rxInit();
  OdDgLambertConformalConicBelgianCoordinateSystem::rxInit();
  OdDgLambertConformalConicWCCSCoordinateSystem::rxInit();
  OdDgTransverseMercatorWCCSCoordinateSystem::rxInit();
  OdDgLambertConformalConicMCoordinateSystem::rxInit();
  OdDgTransverseMercatorMCoordinateSystem::rxInit();
  OdDgTransverseMercatorRSACoordinateSystem::rxInit();
  OdDgUniversalTransverseMercatorCoordinateSystem::rxInit();
  OdDgTransverseMercatorSnyderCoordinateSystem::rxInit();
  OdDgGaussKrugerCoordinateSystem::rxInit();
  OdDgKrovakCoordinateSystem::rxInit();
  OdDgMercatorSRCoordinateSystem::rxInit();
  OdDgObliqueConformalConicCoordinateSystem::rxInit();
  OdDgKrovak95CoordinateSystem::rxInit();
  OdDgPolarStereographicSLCoordinateSystem::rxInit();
  OdDgTransverseMercatorAffineCoordinateSystem::rxInit();
  OdDgNonEarthCoordinateSystem::rxInit();
  OdDgObliqueCylindricalCoordinateSystem::rxInit();
  OdDgDanishSystemKMS2001CoordinateSystem::rxInit();
  OdDgTransverseMercatorOSTN97CoordinateSystem::rxInit();
  OdDgAzimuthalEquidistantCoordinateSystem::rxInit();
  OdDgTransverseMercatorOSTN02CoordinateSystem::rxInit();
  OdDgDanishSystemNoKMSCoordinateSystem::rxInit();
  OdDgTransverseMercatorKFCoordinateSystem::rxInit();
  OdDgWinkelTripelCoordinateSystem::rxInit();
  OdDgNerthSRCoordinateSystem::rxInit();
  OdDgLambertConformalConicAffineCoordinateSystem::rxInit();
  OdDgDanishSystemKMS1999CoordinateSystem::rxInit();
  OdDgEquidistantCylindricalECoordinateSystem::rxInit();
  OdDgPlateCarreeCoordinateSystem::rxInit();
  OdDgPseudoMercatorCoordinateSystem::rxInit();
  OdDgUniversalTransverseMercatorBFCoordinateSystem::rxInit();
  OdDgTransverseMercatorBFCoordinateSystem::rxInit();
  OdDgObliqueMercator1PtUVCoordinateSystem::rxInit();
  OdDgObliqueMercator1PtXYCoordinateSystem::rxInit();
  OdDgObliqueMercator2PtUVCoordinateSystem::rxInit();
  OdDgObliqueMercator2PtXYCoordinateSystem::rxInit();
  OdDgRectifiedSkewOrthoAOCoordinateSystem::rxInit();
  OdDgRectifiedSkewOrthoCCoordinateSystem::rxInit();
  OdDgRectifiedSkewOrthoIsectCoordinateSystem::rxInit();
  OdDgKMLPlacemarkSource::rxInit();
  OdDgFileKMLPlacemark::rxInit();
  OdDgGCSKMLPlacemark::rxInit();
  OdDgDatumKMLPlacemark::rxInit();
  OdDgECClassInstance::rxInit();
  OdDgECCustomClassInstance::rxInit();
  OdDgAlwaysExpandClassInstance::rxInit();
  OdDgArrayBehaviorAttributesClassInstance::rxInit();
  OdDgArrayMemberNameFromValueClassInstance::rxInit();
  OdDgLocalizableClassInstance::rxInit();
  OdDgBooleanDisplayClassInstance::rxInit();
  OdDgCategoryClassInstance::rxInit();
  OdDgStringLengthClassInstance::rxInit();
  OdDgClassPriorityClassInstance::rxInit();
  OdDgDontLoadPropertyClassInstance::rxInit();
  OdDgDontShowNullPropertiesClassInstance::rxInit();
  OdDgDontShowNullPropertyClassInstance::rxInit();
  OdDgDWGFormatClassInstance::rxInit();
  OdDgDWGPropertyClassInstance::rxInit();
  OdDgExtendTypeClassInstance::rxInit();
  OdDgFilePickerAttributesClassInstance::rxInit();
  OdDgFormatClassInstance::rxInit();
  OdDgHideMembersClassInstance::rxInit();
  OdDgHidePropertyClassInstance::rxInit();
  OdDgIgnoreZClassInstance::rxInit();
  OdDgItemTypeSelectorOptInClassInstance::rxInit();
  OdDgMemberExtendedTypeClassInstance::rxInit();
  OdDgMembersIndependentClassInstance::rxInit();
  OdDgPropertyPriorityClassInstance::rxInit();
  OdDgRequiresRefreshClassInstance::rxInit();
  OdDgRequiresReloadClassInstance::rxInit();
  OdDgSchemaPriorityClassInstance::rxInit();
  OdDgValueMapClassInstance::rxInit();
  OdDgStandardValuesClassInstance::rxInit();
  OdDgStoresUnitsAsUorsClassInstance::rxInit();
  OdDgStrikethroughSpecificationClassInstance::rxInit();
  OdDgUseBooleanInExpressionsClassInstance::rxInit();
  OdDgCommentClassInstance::rxInit();
  OdDgRgbColorClassInstance::rxInit();
  OdDgDgnElementColorClassInstance::rxInit();
  OdDgGradientKeyColorClassInstance::rxInit();
  OdDgGradientInfoClassInstance::rxInit();
  OdDgDgnElementFillColorClassInstance::rxInit();
  OdDgAnyClassClassInstance::rxInit();
  OdDgECSchemaInfoClassInstance::rxInit();
  OdDgInstanceCountClassInstance::rxInit();
  OdDgAdHocContainerClassInstance::rxInit();
  OdDgAllowDuplicateLocalizedValuesClassInstance::rxInit();
  OdDgPropertyReferencePropertiesClassInstance::rxInit();
  OdDgBusinessKeySpecificationClassInstance::rxInit();
  OdDgCalculatedECPropertySpecificationClassInstance::rxInit();
  OdDgTabDisplaySpecificationClassInstance::rxInit();
  OdDgCEContentPaneCustomizationClassInstance::rxInit();
  OdDgChangeManagementClassInstance::rxInit();
  OdDgClassReferencePropertiesClassInstance::rxInit();
  OdDgCustomImageSpecificationClassInstance::rxInit();
  OdDgCustomStructSerializerClassInstance::rxInit();
  OdDgDefinitionMetaDataClassInstance::rxInit();
  OdDgDgnECRelationshipOptionsClassInstance::rxInit();
  OdDgDGNPersistedGeometryClassInstance::rxInit();
  OdDgDictionaryCustomAttributesClassInstance::rxInit();
  OdDgDisplayOptionsClassInstance::rxInit();
  OdDgItemsSchemaIdentifierClassInstance::rxInit();
  OdDgFileDependentPropertiesClassInstance::rxInit();
  OdDgFolderDependentPropertiesClassInstance::rxInit();
  OdDgGlobalIdSpecificationClassInstance::rxInit();
  OdDgIdentificationOfActivityPropertiesClassInstance::rxInit();
  OdDgIdentificationOfStandardClassesClassInstance::rxInit();
  OdDgIdentificationOfUserGroupPropertiesClassInstance::rxInit();
  OdDgIdentificationOfUserPropertiesClassInstance::rxInit();
  OdDgInstanceLabelSpecificationClassInstance::rxInit();
  OdDgClassLabelIsInstanceLabelClassInstance::rxInit();
  OdDgInstanceSortingOptionsClassInstance::rxInit();
  OdDgISO15926MetaDataClassInstance::rxInit();
  OdDgItemsBrowserTreePresentationClassInstance::rxInit();
  OdDgLocalizationDataClassInstance::rxInit();
  OdDgLocalizationSpecificationClassInstance::rxInit();
  OdDgPreviousNameClassInstance::rxInit();
  OdDgPreviousNameArrayClassInstance::rxInit();
  OdDgPrimarySchemaMetaDataClassInstance::rxInit();
  OdDgPropertyTemplateMetadataClassInstance::rxInit();
  OdDgPropertyTransformationExpressionClassInstance::rxInit();
  OdDgReferenceTypeRelationshipClassInstance::rxInit();
  OdDgRelatedItemsDisplaySpecificationClassInstance::rxInit();
  OdDgRelatedItemsDisplaySpecificationsClassInstance::rxInit();
  OdDgRelatesToExtendedPropertyObjectClassInstance::rxInit();
  OdDgSchemaFinalizationInfoClassInstance::rxInit();
  OdDgSchemaChangeTrackingStateClassInstance::rxInit();
  OdDgSupplementalSchemaMetaDataClassInstance::rxInit();
  OdDgSupportsOrderedRelationshipsClassInstance::rxInit();
  OdDgOrderedRelationshipsConstraintClassInstance::rxInit();
  OdDgAssociatedStringConstraintClassInstance::rxInit();
  OdDgSupportsRelationshipPropertiesClassInstance::rxInit();
  OdDgSyncIDSpecificationClassInstance::rxInit();
  OdDgTreeColorCustomAttributesClassInstance::rxInit();
  OdDgTransformationValueMapsClassInstance::rxInit();
  OdDgTransformationValueMapClassInstance::rxInit();
  OdDgValueMapEntryClassInstance::rxInit();
  OdDgStrictComparisonOnlyClassInstance::rxInit();
  OdDgDateTimeInfoClassInstance::rxInit();
  OdDgECDbSchemaHintClassInstance::rxInit();
  OdDgECDbPropertyHintClassInstance::rxInit();
  OdDgECDbIndexClassInstance::rxInit();
  OdDgECDbForeignKeyConstraintClassInstance::rxInit();
  OdDgECDbRelationshipConstraintHintClassInstance::rxInit();
  OdDgECDbClassHintClassInstance::rxInit();
  OdDgECDbRelationshipClassHintClassInstance::rxInit();
  OdDgDynamicSchemaClassInstance::rxInit();
  OdDgSystemSchemaClassInstance::rxInit();
  OdDgPersistStringsAsUtf8ClassInstance::rxInit();
  OdDgSchemaNameAndPurposeClassInstance::rxInit();
  OdDgSupplementalProvenanceClassInstance::rxInit();
  OdDgSearchOptionsClassInstance::rxInit();
  OdDgAdhocPropertyContainerDefinitionClassInstance::rxInit();
  OdDgAdhocPropertySpecificationClassInstance::rxInit();
  OdDgClassHasCurrentTimeStampPropertyClassInstance::rxInit();
  OdDgIsSymmetricalRelationshipClassInstance::rxInit();
  OdDgPresentationFilterMetadataClassInstance::rxInit();
  OdDgForceAbstractClassInstance::rxInit();
  OdDgForceCustomAttributeClassClassInstance::rxInit();
  OdDgForceEntityClassClassInstance::rxInit();
  OdDgForceSealedClassInstance::rxInit();
  OdDgForceStructClassClassInstance::rxInit();
  OdDgDropClassClassInstance::rxInit();
  OdDgResolvePropertyNameConflictsClassInstance::rxInit();
  OdDgResolveClassNameConflictsClassInstance::rxInit();
  OdDgOverwriteCardinalityClassInstance::rxInit();
  OdDgIgnoreBaseClassClassInstance::rxInit();
  OdDgMDB_AttributesClassInstance::rxInit();
  OdDgRDL_AttributesClassInstance::rxInit();
  OdDgUseSIUnitSystemDefaultsClassInstance::rxInit();
  OdDgDimension_AttributesClassInstance::rxInit();
  OdDgDisplayUnitSpecificationClassInstance::rxInit();
  OdDgDisplayUnitSpecificationsClassInstance::rxInit();
  OdDgIsUnitSystemSchemaClassInstance::rxInit();
  OdDgKindOfQuantity_AttributesClassInstance::rxInit();
  OdDgMixed_UnitSystemClassInstance::rxInit();
  OdDgSI_UnitSystemClassInstance::rxInit();
  OdDgUnit_AttributesClassInstance::rxInit();
  OdDgUnitSpecificationClassInstance::rxInit();
  OdDgUnitSpecificationsClassInstance::rxInit();
  OdDgUS_UnitSystemClassInstance::rxInit();
  OdDgUseUSCustomaryUnitSystemDefaultsClassInstance::rxInit();
  OdDgIsDgnPlatformDeliveredSchemaClassInstance::rxInit();
  OdDgRelationshipIsNotStoredClassInstance::rxInit();
  OdDgDgnECClassAttributesClassInstance::rxInit();
  OdDgDgnECRelationshipAttributesClassInstance::rxInit();
  OdDgDgnSymbologyOptionsClassInstance::rxInit();
  OdDgUnitDefinitionExtendedTypeOptionsClassInstance::rxInit();
  OdDgDgnStyleOptionsClassInstance::rxInit();
  OdDgItemDisplayAttributeClassInstance::rxInit();
  OdDgPropertyDependencyConditionClassInstance::rxInit();
  OdDgAnyAreBoundPropertyDependencyConditionClassInstance::rxInit();
  OdDgDoesNotSupportPropertyDependencyClassInstance::rxInit();
  OdDgUndisplayedCustomPropertyClassInstance::rxInit();
  OdDgItemTypeLibraryComponentAttributesClassInstance::rxInit();
  OdDgUpgradedTagSetAttributesClassInstance::rxInit();
  OdDgUpgradedTagDefAttributesClassInstance::rxInit();
  OdDgDisplayRulesOptionsClassInstance::rxInit();
  OdDgItemIdentifiesHostClassInstance::rxInit();
  OdDgPresentationCapabilityRequirementClassInstance::rxInit();
  OdDgECXDPersistenceHandlerClassInstance::rxInit();
  OdDgIsDwgAttributeDefinitionsSchemaClassInstance::rxInit();
  OdDgECSchema::rxInit();
  OdDgECProperty::rxInit();
  OdDgECArrayProperty::rxInit();
  OdDgECStructProperty::rxInit();
  OdDgECRelationship::rxInit();
  OdDgECClass::rxInit();
  OdDgECRelationshipClass::rxInit();
  OdDgTerrain::rxInit();
  OdDgTerrainControlElement::rxInit();
  OdDgTableElement::rxInit();
  OdDgTableCellElement::rxInit();
  OdDgTableRowElement::rxInit();
  OdDgTableColumnElement::rxInit();
  OdDgExtendedGraphicsElement::rxInit();
  OdDgRasterHeader2d::rxInit();
  OdDgRasterHeader3d::rxInit();
  OdDgRasterComponent::rxInit();
  OdDgRasterAttachmentHeader::rxInit();
  OdDgRasterAttachmentComponent::rxInit();
  OdDgRasterAttachmentComponentBinary::rxInit();
  OdDgRasterAttachmentComponentContinuous::rxInit();
  OdDgRasterAttachmentComponentRGB::rxInit();
  OdDgRasterAttachmentComponentClip::rxInit();
  OdDgRasterAttachmentComponentColorTable::rxInit();
  OdDgRasterAttachmentComponentGeo::rxInit();
  OdDgRasterAttachmentComponentRender::rxInit();
  OdDgRasterAttachmentComponentTransparency::rxInit();
  OdDgRasterAttachmentComponentRGBTransparency::rxInit();
  OdDgRasterAttachmentComponentMask::rxInit();
  OdDgNamedGroupHeader::rxInit();
  OdDgNamedGroupComponent::rxInit();
  OdDgLineStyleResource::rxInit();
  OdDgPointSymbolResource::rxInit();
  OdDgCompoundLineStyleResource::rxInit();
  OdDgLineCodeResource::rxInit();
  OdDgLinePointResource::rxInit();
  if (DAT_18101ea40 != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)&local_res18,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_res18,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString((OdString *)&local_res18,(ushort *)L"OdDgLineStyleUnknownResource");
  DAT_18101ea40 =
       newOdRxClass((OdString *)&local_res18,OdDgLineStyleResource::g_pDesc,FUN_180060d80,0,0,0,
                    (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                    (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                    (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString((OdString *)&local_res18);
  OdDgAssocPointRoot::rxInit();
  OdDgUnknownAssociation::rxInit();
  OdDgLinearAssociation::rxInit();
  OdDgIntersectAssociation::rxInit();
  OdDgArcAssociation::rxInit();
  OdDgMultilineAssociation::rxInit();
  OdDgBSplineCurveAssociation::rxInit();
  OdDgProjectionAssociation::rxInit();
  OdDgOriginAssociation::rxInit();
  OdDgIntersect2Association::rxInit();
  OdDgMeshVertexAssociation::rxInit();
  OdDgMeshEdgeAssociation::rxInit();
  OdDgBSplineSurfaceAssociation::rxInit();
  OdDgTableRecord::rxInit();
  OdDgLevelMaskIndexTableRecord::rxInit();
  OdDgLevelTableRecord::rxInit();
  OdDgLevelFilterTableRecord::rxInit();
  OdDgFontTableRecord::rxInit();
  OdDgTextStyleTableRecord::rxInit();
  OdDgDimStyleTableRecord::rxInit();
  OdDgMultilineStyleTableRecord::rxInit();
  OdDgLineStyleTableRecord::rxInit();
  OdDgLineStyleDefTableRecord::rxInit();
  OdDgDictionaryTableRecord::rxInit();
  OdDgRegAppTableRecord::rxInit();
  OdDgMaterialTableRecord::rxInit();
  OdDgDictionary::rxInit();
  if (DAT_18101e9c8 != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)&local_res18,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_res18,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString((OdString *)&local_res18,(ushort *)L"OdDgTextStyleTableRecordEx");
  DAT_18101e9c8 =
       newOdRxClass((OdString *)&local_res18,OdDgTextStyleTableRecord::g_pDesc,FUN_180066460,0,0,0,
                    (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                    (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                    (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString((OdString *)&local_res18);
  if (DAT_18101e9c8 != (OdRxClass *)0x0) {
    pOVar3 = odDgnClassMap();
    FUN_180137ee0(pOVar3,0xffff,0xff);
  }
  OdDgTable::rxInit();
  OdDgLevelMaskIndexTable::rxInit();
  OdDgLevelTable::rxInit();
  OdDgLevelFilterTable::rxInit();
  OdDgFontTable::rxInit();
  OdDgTextStyleTable::rxInit();
  OdDgDimStyleTable::rxInit();
  OdDgMaterialTable::rxInit();
  OdDgMultilineStyleTable::rxInit();
  OdDgLineStyleTable::rxInit();
  OdDgLineStyleDefTable::rxInit();
  OdDgDictionaryTable::rxInit();
  OdDgRegAppTable::rxInit();
  OdDgMaterialPattern::rxInit();
  OdDgMaterialLayerPattern::rxInit();
  OdDgView::rxInit();
  OdDgViewGroup::rxInit();
  OdDgLevelMask::rxInit();
  OdDgReferenceAttachmentLevelMaskGroup::rxInit();
  OdDgReferenceAttachmentHeader::rxInit();
  OdDgMatrixHeader::rxInit();
  OdDgMatrixIntegerData::rxInit();
  OdDgMatrixDoubleData::rxInit();
  OdDgMesh::rxInit();
  OdDgMeshFaceLoops::rxInit();
  OdDgMeshPointCloud::rxInit();
  OdDgMeshTriangleList::rxInit();
  OdDgMeshQuadList::rxInit();
  OdDgMeshTriangleGrid::rxInit();
  OdDgMeshQuadGrid::rxInit();
  OdDgReferenceOverride::rxInit();
  OdDgReferenceOrder::rxInit();
  OdDgReferenceLayout::rxInit();
  OdDgPrototypeElementTable::rxInit();
  OdDgPrototypeElement::rxInit();
  OdDgLightDistant::rxInit();
  OdDgLightPoint::rxInit();
  OdDgLightSpot::rxInit();
  OdDgLightArea::rxInit();
  OdDgLightOpenSky::rxInit();
  OdDgKMLPlacemark2d::rxInit();
  OdDgKMLPlacemark3d::rxInit();
  OdDgDetailingSymbolCellHeader2d::rxInit();
  OdDgDetailingSymbolCellHeader3d::rxInit();
  OdDgTitleText2d::rxInit();
  OdDgTitleText3d::rxInit();
  OdDgSectionMarker2d::rxInit();
  OdDgSectionMarker3d::rxInit();
  OdDgArrowMarker2d::rxInit();
  OdDgArrowMarker3d::rxInit();
  OdDgDetailMarker2d::rxInit();
  OdDgDetailMarker3d::rxInit();
  OdDgHatchPattern::rxInit();
  OdDgLinearHatchPattern::rxInit();
  OdDgCrossHatchPattern::rxInit();
  OdDgSymbolHatchPattern::rxInit();
  OdDgProxyHatchPattern::rxInit();
  OdDgDWGHatchPattern::rxInit();
  OdDgLinkNode::rxInit();
  OdDgUnknownLinkNode::rxInit();
  OdDgFolderLinkNode::rxInit();
  OdDgFileLinkNode::rxInit();
  OdDgModelLinkNode::rxInit();
  OdDgRegionLinkNode::rxInit();
  OdDgPdfRegionLinkNode::rxInit();
  OdDgExcelSheetLinkNode::rxInit();
  OdDgWordHeadingLinkNode::rxInit();
  OdDgWordRegionLinkNode::rxInit();
  OdDgURLLinkNode::rxInit();
  OdDgSectionClip::rxInit();
  OdDgEnvironmentMapTable::rxInit();
  OdDgDisplayStyleTable::rxInit();
  OdDgDisplayStyleTableRecord::rxInit();
  OdDgOle2Frame2d::rxInit();
  OdDgOle2Frame3d::rxInit();
  OdDgACS::rxInit();
  OdDgImageBackground::rxInit();
  OdDgWhiteMaterial::rxInit();
  OdDgModelSheetDraw::rxInit();
  OdDgProxyElement::rxInit();
  OdDgProxyGraphicsElement::rxInit();
  OdDgComplexProxyElement::rxInit();
  OdDgComplexProxyGraphicsElement::rxInit();
  OdDgModel::rxInit();
  OdDgModelSheetPE::rxInit();
  OdDgViewGroupTable::rxInit();
  OdDgNamedViewTable::rxInit();
  OdDgPrintStyleTable::rxInit();
  OdDgModelTable::rxInit();
  OdDgSharedCellDefinitionTable::rxInit();
  OdDgTagDefinitionSetTable::rxInit();
  OdDgTagDefinition::rxInit();
  OdDgTagDefinitionDgnStore::rxInit();
  OdDgTagDefinitionXml::rxInit();
  OdDgTagDefinitionDgnOle::rxInit();
  OdDgDgnStoreHeader::rxInit();
  OdDgNonModelElementCollection::rxInit();
  OdDgElementTemplateTable::rxInit();
  OdDgLinkSetTable::rxInit();
  OdDgColorBookTable::rxInit();
  OdDgSheetModel::rxInit();
  OdDgDatabase::rxInit();
  OdDgDatabaseReactor::rxInit();
  OdDgElementReactor::rxInit();
  OdDgModelReactor::rxInit();
  OdDgSummaryInformation::rxInit();
  OdDgDocumentSummaryInformation::rxInit();
  OdDgPropertyValue::rxInit();
  OdGiContextForDgDatabase::rxInit();
  OdGiContextForDgDatabaseToDisplayStyleSupport::rxInit();
  OdGiContextForDgDatabaseToPlotStyleSupport::rxInit();
  OdGiContextForDgDatabaseToExport::rxInit();
  OdGsDeviceForDgModel::rxInit();
  FUN_180136390();
  OdGiAuxDataForDgDatabase::rxInit();
  OdDgElementIterator::rxInit();
  OdDgDictionaryIterator::rxInit();
  OdDgPsPlotStyle::rxInit();
  if (DAT_18101f278 != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)&local_res18,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_res18,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString((OdString *)&local_res18,(ushort *)L"OdDgInternalPlotStyle");
  DAT_18101f278 =
       newOdRxClass((OdString *)&local_res18,OdDgElement::g_pDesc,FUN_18005f300,0,0,0,
                    (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                    (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                    (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString((OdString *)&local_res18);
  OdDgn7IOModule::rxInit();
  OdDgPsPlotStyleServices::rxInit();
  OdDgModelerGeometry::rxInit();
  OdDgModelerGeometryCreator::rxInit();
  OdDgRxDisplayAsAttribute::rxInit();
  OdDgRxHierarchyLevelAttribute::rxInit();
  piVar6 = (int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
                  4);
  if (*piVar6 < DAT_18101fb90) {
    _Init_thread_header(&DAT_18101fb90);
    if (DAT_18101fb90 == -1) {
      atexit((_func_5014 *)&LAB_180a20980);
      _Init_thread_footer(&DAT_18101fb90);
    }
  }
  pOVar4 = OdDbBaseDatabasePE::desc();
  pOVar5 = OdDgDatabase::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fb94) {
    _Init_thread_header(&DAT_18101fb94);
    if (DAT_18101fb94 == -1) {
      atexit((_func_5014 *)&LAB_180a20990);
      _Init_thread_footer(&DAT_18101fb94);
    }
  }
  pOVar4 = OdDbBaseVisualStylePE::desc();
  OdRxClass::addX(OdDgDisplayStyleTableRecord::g_pDesc,(OdRxClass *)&local_res18,
                  (OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fb98) {
    _Init_thread_header(&DAT_18101fb98);
    if (DAT_18101fb98 == -1) {
      atexit((_func_5014 *)&LAB_180a20970);
      _Init_thread_footer(&DAT_18101fb98);
    }
  }
  pOVar4 = OdDbBaseMaterialPE::desc();
  OdRxClass::addX(OdDgMaterialTableRecord::g_pDesc,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDbBaseMaterialPE::desc();
  OdRxClass::addX(OdDgWhiteMaterial::g_pDesc,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fb9c) {
    _Init_thread_header(&DAT_18101fb9c);
    if (DAT_18101fb9c == -1) {
      atexit((_func_5014 *)&LAB_180a208c0);
      _Init_thread_footer(&DAT_18101fb9c);
    }
  }
  pOVar4 = OdDbBaseBlockPE::desc();
  pOVar5 = OdDgSharedCellDefinition::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDbBaseBlockPE::desc();
  OdRxClass::addX(OdDgModel::g_pDesc,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDbBaseBlockPE::desc();
  OdRxClass::addX(OdDgNamedGroupHeader::g_pDesc,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fba0) {
    _Init_thread_header(&DAT_18101fba0);
    if (DAT_18101fba0 == -1) {
      atexit((_func_5014 *)&LAB_180a208d0);
      _Init_thread_footer(&DAT_18101fba0);
    }
  }
  pOVar4 = OdDbBaseBlockRefPE::desc();
  pOVar5 = OdDgGraphicsElement::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDbBaseBlockRefPE::desc();
  pOVar5 = OdDgSharedCellReference::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDbBaseBlockRefPE::desc();
  OdRxClass::addX(OdDgReferenceAttachmentHeader::g_pDesc,(OdRxClass *)&local_res18,
                  (OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fba4) {
    _Init_thread_header(&DAT_18101fba4);
    if (DAT_18101fba4 == -1) {
      atexit((_func_5014 *)&LAB_180a20940);
      _Init_thread_footer(&DAT_18101fba4);
    }
  }
  pOVar4 = OdDbBaseLayerPE::desc();
  OdRxClass::addX(OdDgLevelTableRecord::g_pDesc,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fba8) {
    _Init_thread_header(&DAT_18101fba8);
    if (DAT_18101fba8 == -1) {
      atexit((_func_5014 *)&LAB_180a20950);
      _Init_thread_footer(&DAT_18101fba8);
    }
  }
  pOVar4 = OdDbBaseLayoutPE::desc();
  OdRxClass::addX(OdDgModel::g_pDesc,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDbBaseLayoutPE::desc();
  OdRxClass::addX(OdDgViewGroup::g_pDesc,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fbb8) {
    _Init_thread_header(&DAT_18101fbb8);
    if (DAT_18101fbb8 == -1) {
      OdDbEntityHyperlinkPE::OdDbEntityHyperlinkPE((OdDbEntityHyperlinkPE *)&DAT_18101fbb0);
      _DAT_18101fbb0 = OdStaticRxObject<OdDgEntityHyperlinkPEImpl>::vftable;
      atexit((_func_5014 *)&LAB_180a20930);
      _Init_thread_footer(&DAT_18101fbb8);
    }
  }
  pOVar4 = OdDbEntityHyperlinkPE::desc();
  OdRxClass::addX(OdDgElement::g_pDesc,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  OdDgBRepEntityPE::rxInit();
  OdDgReferenceAttachClipBoundaryPE::rxInit();
  OdDgReferenceAttachCDAPE::rxInit();
  OdDgAbstractViewPE::rxInit();
  if (*piVar6 < DAT_18101fbd0) {
    _Init_thread_header(&DAT_18101fbd0);
    if (DAT_18101fbd0 == -1) {
      OdDgBRepEntityPE::OdDgBRepEntityPE((OdDgBRepEntityPE *)&DAT_18101fbc0);
      _DAT_18101fbc0 = OdStaticRxObject<OdDgBRepEntityPE>::vftable;
      atexit((_func_5014 *)&LAB_180a20880);
      _Init_thread_footer(&DAT_18101fbd0);
    }
  }
  pOVar4 = OdDgBRepEntityPE::desc();
  pOVar5 = OdDgCellHeader3d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fbd4) {
    _Init_thread_header(&DAT_18101fbd4);
    if (DAT_18101fbd4 == -1) {
      atexit((_func_5014 *)&LAB_180a20de0);
      _Init_thread_footer(&DAT_18101fbd4);
    }
  }
  pOVar4 = OdDgReferenceAttachClipBoundaryPE::desc();
  OdRxClass::addX(OdDgReferenceAttachmentHeader::g_pDesc,(OdRxClass *)&local_res18,
                  (OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fbd8) {
    _Init_thread_header(&DAT_18101fbd8);
    if (DAT_18101fbd8 == -1) {
      atexit((_func_5014 *)&LAB_180a20dd0);
      _Init_thread_footer(&DAT_18101fbd8);
    }
  }
  pOVar4 = OdDgReferenceAttachCDAPE::desc();
  OdRxClass::addX(OdDgReferenceAttachmentHeader::g_pDesc,(OdRxClass *)&local_res18,
                  (OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fbdc) {
    _Init_thread_header(&DAT_18101fbdc);
    if (DAT_18101fbdc == -1) {
      atexit((_func_5014 *)&LAB_180a20890);
      _Init_thread_footer(&DAT_18101fbdc);
    }
  }
  pOVar4 = OdAbstractViewPE::desc();
  OdRxClass::addX(OdDgView::g_pDesc,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  OdDgDatabaseLockFlagsPE::rxInit();
  OdDgDatabaseHandleLimitPE::rxInit();
  OdDgMaterialAssignmentElementPE::rxInit();
  OdDgECClassInstanceElementPE::rxInit();
  OdDg2d3dConversionGraphicsElementPE::rxInit();
  OdDgDisplayStyleGraphicsElementPE::rxInit();
  OdDgLineStyleDataElementPE::rxInit();
  OdDgAnnotativeObjectPE::rxInit();
  OdDgBrepBuilderInitialDataPE::rxInit();
  OdDgBSplineSurfaceBrepBuilderInitialDataPE::rxInit();
  OdDgConeBrepBuilderInitialDataPE::rxInit();
  OdDg3dSolidBrepBuilderInitialDataPE::rxInit();
  OdDgDatabaseRecoveryPE::rxInit();
  OdDgLinkNodeElementPE::rxInit();
  OdDgGraphicsElementPE::rxInit();
  OdDgTextMirrorControlPE::rxInit();
  OdDgElementIntersectionPE::rxInit();
  OdDgImportLineStylePE::rxInit();
  OdDgLoadLineStyleFromLinFilePE::rxInit();
  OdDgBSplineCurve2dPE::rxInit();
  OdDgBSplineCurve3dPE::rxInit();
  OdDgCurveElement2dPE::rxInit();
  OdDgCurveElement3dPE::rxInit();
  OdDgDimensionExportPE::rxInit();
  OdDgRecomputeDimPointsPE::rxInit();
  OdDgRecomputeMLinePointsPE::rxInit();
  OdDgCellBoundaryClipPE::rxInit();
  OdDgAssocRegionRecalculatePE::rxInit();
  OdDgFontTablePE::rxInit();
  OdDgDisplayStyleViewPE::rxInit();
  OdDgElementXDataPE::rxInit();
  OdDgDwgReferenceAttachmentPE::rxInit();
  OdDgProxyElementGraphicsCachePE::rxInit();
  if (*piVar6 < DAT_18101fbf0) {
    _Init_thread_header(&DAT_18101fbf0);
    if (DAT_18101fbf0 == -1) {
      OdDgAnnotativeObjectPE::OdDgAnnotativeObjectPE((OdDgAnnotativeObjectPE *)&DAT_18101fbe0);
      _DAT_18101fbe0 = OdStaticRxObject<OdDgAnnotativeObjectPE>::vftable;
      atexit((_func_5014 *)&LAB_180a20910);
      _Init_thread_footer(&DAT_18101fbf0);
    }
  }
  pOVar4 = OdDgAnnotativeObjectPE::desc();
  OdRxClass::addX(OdDgModel::g_pDesc,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgAnnotativeObjectPE::desc();
  pOVar5 = OdDgDimension::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgAnnotativeObjectPE::desc();
  pOVar5 = OdDgSharedCellReference::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgAnnotativeObjectPE::desc();
  pOVar5 = OdDgAnnotationCellHeader2d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgAnnotativeObjectPE::desc();
  pOVar5 = OdDgAnnotationCellHeader3d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgAnnotativeObjectPE::desc();
  pOVar5 = OdDgText2d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgAnnotativeObjectPE::desc();
  pOVar5 = OdDgText3d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgAnnotativeObjectPE::desc();
  pOVar5 = OdDgTextNode2d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgAnnotativeObjectPE::desc();
  pOVar5 = OdDgTextNode3d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgAnnotativeObjectPE::desc();
  pOVar5 = OdDgTableElement::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgAnnotativeObjectPE::desc();
  pOVar5 = OdDgTitleText2d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgAnnotativeObjectPE::desc();
  pOVar5 = OdDgTitleText3d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgAnnotativeObjectPE::desc();
  pOVar5 = OdDgSectionMarker2d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgAnnotativeObjectPE::desc();
  pOVar5 = OdDgSectionMarker3d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgAnnotativeObjectPE::desc();
  pOVar5 = OdDgArrowMarker2d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgAnnotativeObjectPE::desc();
  pOVar5 = OdDgArrowMarker3d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgAnnotativeObjectPE::desc();
  pOVar5 = OdDgDetailMarker2d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgAnnotativeObjectPE::desc();
  pOVar5 = OdDgDetailMarker3d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgAnnotativeObjectPE::desc();
  pOVar5 = OdDgTagElement::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fc08) {
    _Init_thread_header(&DAT_18101fc08);
    if (DAT_18101fc08 == -1) {
      OdDgDatabaseLockFlagsPE::OdDgDatabaseLockFlagsPE((OdDgDatabaseLockFlagsPE *)&DAT_18101fbf8);
      _DAT_18101fbf8 = OdStaticRxObject<OdDgDatabaseLockFlagsPE>::vftable;
      atexit((_func_5014 *)&LAB_180a20960);
      _Init_thread_footer(&DAT_18101fc08);
    }
  }
  pOVar4 = OdDgDatabaseLockFlagsPE::desc();
  pOVar5 = OdDgDatabase::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fc20) {
    _Init_thread_header(&DAT_18101fc20);
    if (DAT_18101fc20 == -1) {
      OdDgDatabaseHandleLimitPE::OdDgDatabaseHandleLimitPE
                ((OdDgDatabaseHandleLimitPE *)&DAT_18101fc10);
      _DAT_18101fc10 = OdStaticRxObject<OdDgDatabaseHandleLimitPE>::vftable;
      atexit((_func_5014 *)&LAB_180a20920);
      _Init_thread_footer(&DAT_18101fc20);
    }
  }
  pOVar4 = OdDgDatabaseHandleLimitPE::desc();
  pOVar5 = OdDgDatabase::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fc38) {
    _Init_thread_header(&DAT_18101fc38);
    if (DAT_18101fc38 == -1) {
      OdDgLinkNodeElementPE::OdDgLinkNodeElementPE((OdDgLinkNodeElementPE *)&DAT_18101fc28);
      _DAT_18101fc28 = OdStaticRxObject<OdDgLinkNodeElementPE>::vftable;
      atexit((_func_5014 *)&LAB_180a20a10);
      _Init_thread_footer(&DAT_18101fc38);
    }
  }
  pOVar4 = OdDgLinkNodeElementPE::desc();
  OdRxClass::addX(OdDgElement::g_pDesc,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fc50) {
    _Init_thread_header(&DAT_18101fc50);
    if (DAT_18101fc50 == -1) {
      OdDgGraphicsElementPE::OdDgGraphicsElementPE((OdDgGraphicsElementPE *)&DAT_18101fc40);
      _DAT_18101fc40 = OdStaticRxObject<OdDgGraphicsElementPE>::vftable;
      atexit((_func_5014 *)&LAB_180a209e0);
      _Init_thread_footer(&DAT_18101fc50);
    }
  }
  pOVar4 = OdDgGraphicsElementPE::desc();
  pOVar5 = OdDgGraphicsElement::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fc68) {
    _Init_thread_header(&DAT_18101fc68);
    if (DAT_18101fc68 == -1) {
      OdDgLineStyleDataElementPE::OdDgLineStyleDataElementPE
                ((OdDgLineStyleDataElementPE *)&DAT_18101fc58);
      _DAT_18101fc58 = OdStaticRxObject<OdDgLineStyleDataElementPE>::vftable;
      atexit((_func_5014 *)&LAB_180a20a00);
      _Init_thread_footer(&DAT_18101fc68);
    }
  }
  pOVar4 = OdDgLineStyleDataElementPE::desc();
  pOVar5 = OdDgCurveElement2d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgLineStyleDataElementPE::desc();
  pOVar5 = OdDgCurveElement3d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgLineStyleDataElementPE::desc();
  pOVar5 = OdDgMultiline::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgLineStyleDataElementPE::desc();
  pOVar5 = OdDgSharedCellReference::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fc80) {
    _Init_thread_header(&DAT_18101fc80);
    if (DAT_18101fc80 == -1) {
      OdDgProxyElementGraphicsCachePE::OdDgProxyElementGraphicsCachePE
                ((OdDgProxyElementGraphicsCachePE *)&DAT_18101fc70);
      _DAT_18101fc70 = OdStaticRxObject<OdDgProxyElementGraphicsCachePE>::vftable;
      atexit((_func_5014 *)&LAB_180a20a40);
      _Init_thread_footer(&DAT_18101fc80);
    }
  }
  pOVar4 = OdDgProxyElementGraphicsCachePE::desc();
  pOVar5 = OdDgProxyGraphicsElement::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgProxyElementGraphicsCachePE::desc();
  pOVar5 = OdDgComplexProxyGraphicsElement::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgProxyElementGraphicsCachePE::desc();
  pOVar5 = OdDgExtendedGraphicsElement::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fc98) {
    _Init_thread_header(&DAT_18101fc98);
    if (DAT_18101fc98 == -1) {
      OdDgDisplayStyleGraphicsElementPE::OdDgDisplayStyleGraphicsElementPE
                ((OdDgDisplayStyleGraphicsElementPE *)&DAT_18101fc88);
      _DAT_18101fc88 = OdStaticRxObject<OdDgDisplayStyleGraphicsElementPE>::vftable;
      atexit((_func_5014 *)&LAB_180a209b0);
      _Init_thread_footer(&DAT_18101fc98);
    }
  }
  pOVar4 = OdDgDisplayStyleGraphicsElementPE::desc();
  pOVar5 = OdDgGraphicsElement::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fcb0) {
    _Init_thread_header(&DAT_18101fcb0);
    if (DAT_18101fcb0 == -1) {
      OdDg2d3dConversionGraphicsElementPE::OdDg2d3dConversionGraphicsElementPE
                ((OdDg2d3dConversionGraphicsElementPE *)&DAT_18101fca0);
      _DAT_18101fca0 = OdStaticRxObject<OdDg2d3dConversionGraphicsElementPE>::vftable;
      atexit((_func_5014 *)&LAB_180a20900);
      _Init_thread_footer(&DAT_18101fcb0);
    }
  }
  pOVar4 = OdDg2d3dConversionGraphicsElementPE::desc();
  pOVar5 = OdDgGraphicsElement::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fcb4) {
    _Init_thread_header(&DAT_18101fcb4);
    if (DAT_18101fcb4 == -1) {
      atexit((_func_5014 *)&LAB_180a208b0);
      _Init_thread_footer(&DAT_18101fcb4);
    }
  }
  pOVar4 = OdDgBrepBuilderInitialDataPE::desc();
  pOVar5 = OdDgBSplineSurface::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fcb8) {
    _Init_thread_header(&DAT_18101fcb8);
    if (DAT_18101fcb8 == -1) {
      atexit((_func_5014 *)&LAB_180a208f0);
      _Init_thread_footer(&DAT_18101fcb8);
    }
  }
  pOVar4 = OdDgBrepBuilderInitialDataPE::desc();
  pOVar5 = OdDgCone::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fcbc) {
    _Init_thread_header(&DAT_18101fcbc);
    if (DAT_18101fcbc == -1) {
      atexit((_func_5014 *)&LAB_180a20cd0);
      _Init_thread_footer(&DAT_18101fcbc);
    }
  }
  pOVar4 = OdDgBrepBuilderInitialDataPE::desc();
  pOVar5 = OdDgSolid::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgBrepBuilderInitialDataPE::desc();
  pOVar5 = OdDgSurface::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fcd0) {
    _Init_thread_header(&DAT_18101fcd0);
    if (DAT_18101fcd0 == -1) {
      OdDgMaterialAssignmentElementPE::OdDgMaterialAssignmentElementPE
                ((OdDgMaterialAssignmentElementPE *)&DAT_18101fcc0);
      _DAT_18101fcc0 = OdStaticRxObject<OdDgMaterialAssignmentElementPE>::vftable;
      atexit((_func_5014 *)&LAB_180a20a20);
      _Init_thread_footer(&DAT_18101fcd0);
    }
  }
  pOVar4 = OdDgMaterialAssignmentElementPE::desc();
  OdRxClass::addX(OdDgMaterialTable::g_pDesc,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fce8) {
    _Init_thread_header(&DAT_18101fce8);
    if (DAT_18101fce8 == -1) {
      OdDgECClassInstanceElementPE::OdDgECClassInstanceElementPE
                ((OdDgECClassInstanceElementPE *)&DAT_18101fcd8);
      _DAT_18101fcd8 = OdStaticRxObject<OdDgECClassInstanceElementPE>::vftable;
      atexit((_func_5014 *)&LAB_180a209f0);
      _Init_thread_footer(&DAT_18101fce8);
    }
  }
  pOVar4 = OdDgECClassInstanceElementPE::desc();
  OdRxClass::addX(OdDgElement::g_pDesc,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fd00) {
    _Init_thread_header(&DAT_18101fd00);
    if (DAT_18101fd00 == -1) {
      OdDgDimensionExportPE::OdDgDimensionExportPE((OdDgDimensionExportPE *)&DAT_18101fcf0);
      _DAT_18101fcf0 = OdStaticRxObject<OdDgDimensionExportPE>::vftable;
      atexit((_func_5014 *)&LAB_180a209a0);
      _Init_thread_footer(&DAT_18101fd00);
    }
  }
  pOVar4 = OdDgDimensionExportPE::desc();
  pOVar5 = OdDgDimension::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fd18) {
    _Init_thread_header(&DAT_18101fd18);
    if (DAT_18101fd18 == -1) {
      OdDgCellBoundaryClipPE::OdDgCellBoundaryClipPE((OdDgCellBoundaryClipPE *)&DAT_18101fd08);
      _DAT_18101fd08 = OdStaticRxObject<OdDgCellBoundaryClipPE>::vftable;
      atexit((_func_5014 *)&LAB_180a208e0);
      _Init_thread_footer(&DAT_18101fd18);
    }
  }
  pOVar4 = OdDgCellBoundaryClipPE::desc();
  pOVar5 = OdDgCellHeader2d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgCellBoundaryClipPE::desc();
  pOVar5 = OdDgCellHeader3d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgCellBoundaryClipPE::desc();
  pOVar5 = OdDgSharedCellReference::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fd30) {
    _Init_thread_header(&DAT_18101fd30);
    if (DAT_18101fd30 == -1) {
      OdDgAssocRegionRecalculatePE::OdDgAssocRegionRecalculatePE
                ((OdDgAssocRegionRecalculatePE *)&DAT_18101fd20);
      _DAT_18101fd20 = OdStaticRxObject<OdDgAssocRegionRecalculatePE>::vftable;
      atexit((_func_5014 *)&LAB_180a208a0);
      _Init_thread_footer(&DAT_18101fd30);
    }
  }
  pOVar4 = OdDgAssocRegionRecalculatePE::desc();
  pOVar5 = OdDgAssocRegion2d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  pOVar4 = OdDgAssocRegionRecalculatePE::desc();
  pOVar5 = OdDgAssocRegion3d::desc();
  OdRxClass::addX(pOVar5,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fd48) {
    _Init_thread_header(&DAT_18101fd48);
    if (DAT_18101fd48 == -1) {
      OdDgFontTablePE::OdDgFontTablePE((OdDgFontTablePE *)&DAT_18101fd38);
      _DAT_18101fd38 = OdStaticRxObject<OdDgFontTablePE>::vftable;
      atexit((_func_5014 *)&LAB_180a209d0);
      _Init_thread_footer(&DAT_18101fd48);
    }
  }
  pOVar4 = OdDgFontTablePE::desc();
  OdRxClass::addX(OdDgFontTable::g_pDesc,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (*piVar6 < DAT_18101fd60) {
    _Init_thread_header(&DAT_18101fd60);
    if (DAT_18101fd60 == -1) {
      OdDgDisplayStyleViewPE::OdDgDisplayStyleViewPE((OdDgDisplayStyleViewPE *)&DAT_18101fd50);
      _DAT_18101fd50 = OdStaticRxObject<OdDgDisplayStyleViewPE>::vftable;
      atexit((_func_5014 *)&LAB_180a209c0);
      _Init_thread_footer(&DAT_18101fd60);
    }
  }
  pOVar4 = OdDgDisplayStyleViewPE::desc();
  OdRxClass::addX(OdDgView::g_pDesc,(OdRxClass *)&local_res18,(OdRxObject *)pOVar4);
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  if (DAT_18101f1b0 != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)&local_res18,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_res18,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString((OdString *)&local_res18,(ushort *)L"OdDgFilerController");
  pOVar4 = OdRxObject::desc();
  DAT_18101f1b0 =
       newOdRxClass((OdString *)&local_res18,pOVar4,(_func_OdRxObjectPtr *)0x0,0,0,0,
                    (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                    (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                    (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString((OdString *)&local_res18);
  OdDgFiler::rxInit();
  if (DAT_18101ea10 != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)&local_res18,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_res18,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString((OdString *)&local_res18,(ushort *)L"OdDgOle2Storage");
  pOVar4 = OdRxObject::desc();
  DAT_18101ea10 =
       newOdRxClass((OdString *)&local_res18,pOVar4,(_func_OdRxObjectPtr *)0x0,0,0,0,
                    (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                    (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                    (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString((OdString *)&local_res18);
  if (DAT_18101e9f8 != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)&local_res18,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_res18,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString((OdString *)&local_res18,(ushort *)L"OdDgOle2Stream");
  pOVar4 = OdRxObject::desc();
  DAT_18101e9f8 =
       newOdRxClass((OdString *)&local_res18,pOVar4,(_func_OdRxObjectPtr *)0x0,0,0,0,
                    (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                    (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                    (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString((OdString *)&local_res18);
  OdDgChunk::rxInit();
  if (DAT_18101ed60 != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)&local_res18,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_res18,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString((OdString *)&local_res18,(ushort *)L"OdDgBaseChunk");
  DAT_18101ed60 =
       newOdRxClass((OdString *)&local_res18,OdDgChunk::g_pDesc,(_func_OdRxObjectPtr *)0x0,0,0,0,
                    (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                    (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                    (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString((OdString *)&local_res18);
  if (DAT_18101ed80 != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)&local_res18,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_res18,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString((OdString *)&local_res18,(ushort *)L"OdDgZipChunk");
  DAT_18101ed80 =
       newOdRxClass((OdString *)&local_res18,DAT_18101ed60,(_func_OdRxObjectPtr *)0x0,0,0,0,
                    (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                    (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                    (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString((OdString *)&local_res18);
  if (DAT_18101ef90 != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)&local_res18,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_res18,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString((OdString *)&local_res18,(ushort *)L"OdDgElementChunk");
  DAT_18101ef90 =
       newOdRxClass((OdString *)&local_res18,DAT_18101ed80,(_func_OdRxObjectPtr *)0x0,0,0,0,
                    (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                    (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                    (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString((OdString *)&local_res18);
  if (DAT_18101edb8 != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)&local_res18,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_res18,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString((OdString *)&local_res18,(ushort *)L"OdDgXAttributeChunk");
  DAT_18101edb8 =
       newOdRxClass((OdString *)&local_res18,DAT_18101ed80,(_func_OdRxObjectPtr *)0x0,0,0,0,
                    (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                    (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                    (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString((OdString *)&local_res18);
  OdDgBlock::rxInit();
  if (DAT_18101ea88 != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)&local_res18,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_res18,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString((OdString *)&local_res18,(ushort *)L"OdDgBaseBlock");
  DAT_18101ea88 =
       newOdRxClass((OdString *)&local_res18,OdDgBlock::g_pDesc,(_func_OdRxObjectPtr *)0x0,0,0,0,
                    (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                    (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                    (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString((OdString *)&local_res18);
  if (DAT_18101ebf0 != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)&local_res18,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_res18,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString((OdString *)&local_res18,(ushort *)L"OdDgElementBlock");
  DAT_18101ebf0 =
       newOdRxClass((OdString *)&local_res18,DAT_18101ea88,(_func_OdRxObjectPtr *)0x0,0,0,0,
                    (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                    (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                    (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString((OdString *)&local_res18);
  if (DAT_18101ebc0 != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)&local_res18,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_res18,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString((OdString *)&local_res18,(ushort *)L"OdDgXAttributeBlock");
  DAT_18101ebc0 =
       newOdRxClass((OdString *)&local_res18,DAT_18101ea88,(_func_OdRxObjectPtr *)0x0,0,0,0,
                    (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                    (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                    (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString((OdString *)&local_res18);
  if (DAT_18101efd8 == (OdRxClass *)0x0) {
    OdString::OdString((OdString *)&local_res18,(ushort *)L"OdDgModelBlock");
    DAT_18101efd8 =
         newOdRxClass((OdString *)&local_res18,DAT_18101ea88,(_func_OdRxObjectPtr *)0x0,0,0,0,
                      (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                      (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                      (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
    OdString::~OdString((OdString *)&local_res18);
    if (DAT_18101eb08 != (OdRxClass *)0x0) {
      OdError::OdError((OdError *)&local_res18,0x13a);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_res18,(ThrowInfo *)&DAT_180de52b8);
    }
    OdString::OdString((OdString *)&local_res18,(ushort *)L"OdDgFile");
    DAT_18101eb08 =
         newOdRxClass((OdString *)&local_res18,DAT_18101ea88,(_func_OdRxObjectPtr *)0x0,0,0,0,
                      (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                      (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                      (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
    OdString::~OdString((OdString *)&local_res18);
    if (DAT_18101ebc8 != (OdRxClass *)0x0) {
      OdError::OdError((OdError *)&local_res18,0x13a);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_res18,(ThrowInfo *)&DAT_180de52b8);
    }
    OdString::OdString((OdString *)&local_res18,(ushort *)L"OdDgn8LoadResolver");
    pOVar4 = OdRxObject::desc();
    DAT_18101ebc8 =
         newOdRxClass((OdString *)&local_res18,pOVar4,(_func_OdRxObjectPtr *)0x0,0,0,0,
                      (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                      (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                      (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
    OdString::~OdString((OdString *)&local_res18);
    if (DAT_18101ec80 != (OdRxClass *)0x0) {
      OdError::OdError((OdError *)&local_res18,0x13a);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_res18,(ThrowInfo *)&DAT_180de52b8);
    }
    OdString::OdString((OdString *)&local_res18,(ushort *)L"Dgn8LoadResolverRasterReference");
    DAT_18101ec80 =
         newOdRxClass((OdString *)&local_res18,DAT_18101ebc8,FUN_180058350,0,0,0,
                      (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                      (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                      (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
    OdString::~OdString((OdString *)&local_res18);
    if (DAT_18101f230 == (OdRxClass *)0x0) {
      OdString::OdString((OdString *)&local_res18,(ushort *)L"OdDgXAttributeSet");
      pOVar4 = OdRxObject::desc();
      DAT_18101f230 =
           newOdRxClass((OdString *)&local_res18,pOVar4,FUN_180067ce0,0,0,0,(OdString *)kEmpty_exref
                        ,(OdString *)kEmpty_exref,(_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0
                        ,(_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
      OdString::~OdString((OdString *)&local_res18);
      OdDgAttributeLinkage::rxInit();
      OdDgStringLinkage::rxInit();
      OdDgThicknessLinkage::rxInit();
      OdDgSheetModelLinkage::rxInit();
      OdDgSheetAnnotationScaleLinkage::rxInit();
      OdDgSheetModelExtensionLinkage::rxInit();
      OdDgLineStyleModificationLinkage::rxInit();
      OdDgMaterialLinkage::rxInit();
      OdDgOleLinkage::rxInit();
      OdDgProxyLinkage::rxInit();
      OdDgDependencyLinkage::rxInit();
      OdDgDepLinkageElementId::rxInit();
      OdDgDepLinkageElementIdV::rxInit();
      OdDgDepLinkageAssocPoint::rxInit();
      OdDgDepLinkageAssocPointI::rxInit();
      OdDgDepLinkageFarElementId::rxInit();
      OdDgDepLinkageFarElementIdV::rxInit();
      OdDgDepLinkagePath::rxInit();
      OdDgBrepLinkage::rxInit();
      OdDgSeedPointsLinkage::rxInit();
      OdDgAssocRegionLinkage::rxInit();
      OdDgNoteLinkage::rxInit();
      OdDgDimensionTextStyleDataLinkage::rxInit();
      OdDgPatternLinkage::rxInit();
      OdDgDBLinkage::rxInit();
      OdDgByteArrayLinkage::rxInit();
      OdDgDoubleArrayLinkage::rxInit();
      OdDgBitMaskLinkage::rxInit();
      OdDgTextWhiteSpaceLinkage::rxInit();
      OdDgTextIndentationLinkage::rxInit();
      OdDgFilterMemberLinkage::rxInit();
      OdDgFillColorLinkage::rxInit();
      OdDgGradientFillLinkage::rxInit();
      OdDgInternalMaterialLinkage::rxInit();
      OdDgTransparencyLinkage::rxInit();
      OdDgDMRSLinkage::rxInit();
      OdDgDimensionLinkage::rxInit();
      OdDgDimensionTextItemLinkage::rxInit();
      OdDgDimensionOverallLinkage::rxInit();
      OdDgDimensionSegmentLinkage::rxInit();
      OdDgDimensionPointLinkage::rxInit();
      OdDgDimensionSegmentFlagsLinkage::rxInit();
      OdDgDimensionInfoLinkage::rxInit();
      OdDgReferenceAttachPathLinkage::rxInit();
      OdDgBoundaryClipLinkage::rxInit();
      OdDgDimensionRefValueLinkage::rxInit();
      OdDgDisplayStyleLinkage::rxInit();
      OdDgInfiniteLineLinkage::rxInit();
      OdDgXmlLinkage::rxInit();
      OdDgTextAnnotationLinkage::rxInit();
      OdDgSharedCellFlagsLinkage::rxInit();
      oddgSetLinkageHandler(0x56d2,FUN_1800481a0);
      oddgSetLinkageHandler(0x56d0,FUN_18003be90);
      oddgSetLinkageHandler(0x522e,FUN_1800396f0);
      oddgSetLinkageHandler(0x5751,FUN_1800399c0);
      oddgSetLinkageHandler(0x56dd,FUN_18003ef60);
      oddgSetLinkageHandler(0x79f9,FUN_1808c2490);
      oddgSetLinkageHandler(0x7d28,FUN_18082a450);
      oddgSetLinkageHandler(0x56da,FUN_18082b760);
      oddgSetLinkageHandler(0x562e,FUN_180835c20);
      oddgSetLinkageHandler(0x5801,FUN_180835b40);
      oddgSetLinkageHandler(0x41,FUN_1808bef50);
      oddgSetLinkageHandler(0x56d4,FUN_1808bfd80);
      oddgSetLinkageHandler(0x56e9,FUN_1808ce340);
      oddgSetLinkageHandler(0x56e3,FUN_1808d3d30);
      oddgSetLinkageHandler(0x56ed,FUN_1808c43f0);
      oddgSetLinkageHandler(0x56ee,FUN_1808c4270);
      oddgSetLinkageHandler(0x5701,FUN_1808c4330);
      oddgSetLinkageHandler(0x20,FUN_1808c07f0);
      oddgSetLinkageHandler(0xf81,FUN_1808c07f0);
      oddgSetLinkageHandler(0x1971,FUN_1808c07f0);
      oddgSetLinkageHandler(0x3948,FUN_1808c07f0);
      oddgSetLinkageHandler(0x3a77,FUN_1808c07f0);
      oddgSetLinkageHandler(0x4f58,FUN_1808c07f0);
      oddgSetLinkageHandler(0x5e62,FUN_1808c07f0);
      oddgSetLinkageHandler(0x5800,FUN_1808c07f0);
      oddgSetLinkageHandler(0x6091,FUN_1808c07f0);
      oddgSetLinkageHandler(0x71fb,FUN_1808c07f0);
      oddgSetLinkageHandler(0,FUN_18081d510);
      oddgSetLinkageHandler(0x56de,FUN_180834370);
      oddgSetLinkageHandler(0x4f5a,FUN_1808c14e0);
      oddgSetLinkageHandler(0x56f1,FUN_1808af930);
      oddgSetLinkageHandler(0xb01e,FUN_1808c4d70);
      oddgSetLinkageHandler(0x56d5,FUN_18003d650);
      oddgSetLinkageHandler(0x56d3,FUN_1808accc0);
      oddgSetLinkageHandler(0x5810,FUN_1808ad8a0);
      oddgSetLinkageHandler(0x56dc,FUN_1808caf70);
      oddgSetLinkageHandler(0x56f3,FUN_1808ab3d0);
      oddgSetLinkageHandler(0x56d8,FUN_180829ed0);
      oddgSetLinkageHandler(0x56ea,FUN_1809d8250);
      OdDgXAttribute::rxInit();
      OdDgProxyXAttribute::rxInit();
      OdDgXmlXAttribute::rxInit();
      OdDgZippedXAttribute::rxInit();
      OdDgProcessedXmlXAttribute::rxInit();
      OdDgTrueColorXAttribute::rxInit();
      OdDgMaterialTableExtXAttribute::rxInit();
      OdDgAnnotationCellXAttribute::rxInit();
      OdDgColorBookXAttribute::rxInit();
      OdDgAcsXAttribute::rxInit();
      OdDgDgnLinkNodeXAttribute::rxInit();
      OdDgMaterialXAttribute::rxInit();
      OdDgMatProjectionXAttribute::rxInit();
      OdDgBinXMLXAttribute::rxInit();
      OdDgTemplateHeaderXAttribute::rxInit();
      OdDgTemplateIdXAttribute::rxInit();
      OdDgRasterClipXAttribute::rxInit();
      OdDgPdfLayerVisibilityDifXAttribute::rxInit();
      OdDgTextFieldXAttribute::rxInit();
      OdDgDefaultTextStyleXAttribute::rxInit();
      OdDgDetailingSymbolXAttribute::rxInit();
      OdDgSectionClipDataXAttribute::rxInit();
      OdDgSectionClipDataExtXAttribute::rxInit();
      OdDgEnvironmentMapXAttribute::rxInit();
      OdDgDisplayStyleTypeFilterXAttribute::rxInit();
      OdDgDisplayStyleLegendXAttribute::rxInit();
      OdDgDisplayStyleAzimuthAltitudeXAttribute::rxInit();
      OdDgDisplayStyleNumberXAttribute::rxInit();
      OdDgClipVolumeSettingsXAttribute::rxInit();
      OdDgLuxologySetupXAttribute::rxInit();
      OdDgDisplayStyleXAttribute::rxInit();
      OdDgDisplayStyleExtXAttribute::rxInit();
      OdDgLightExtraDataXAttribute::rxInit();
      OdDgPrintStyleXAttribute::rxInit();
      OdDgTerrainVertexCoordinatesXAttribute::rxInit();
      OdDgTerrainVertexTopologyXAttribute::rxInit();
      OdDgTerrainEdgesXAttribute::rxInit();
      OdDgTerrainStringXAttribute::rxInit();
      OdDgTerrainTransformationXAttribute::rxInit();
      OdDgTerrainInfoXAttribute::rxInit();
      OdDgTerrainFeatureDescriptionXAttribute::rxInit();
      OdDgTerrainFeatureTopologyXAttribute::rxInit();
      OdDgTerrainCorruptedFeatureXAttribute::rxInit();
      OdDgExtendedElementTypeXAttribute::rxInit();
      OdDgTerrainGraphicsSettingsXAttribute::rxInit();
      OdDgTerrainDisplayStyleXAttribute::rxInit();
      OdDgTerrainControlReferenceXAttribute::rxInit();
      OdDgTextStyleDataXAttribute::rxInit();
      OdDgStringXAttribute::rxInit();
      OdDgItemLibNameXAttribute::rxInit();
      OdDgItemLibVersionXAttribute::rxInit();
      OdDgItemLibProviderXAttribute::rxInit();
      OdDgItemTypeXAttribute::rxInit();
      OdDgGeometryCacheXAttribute::rxInit();
      OdDgElementSchemaXAttribute::rxInit();
      OdDgSchemaDescriptionXAttribute::rxInit();
      OdDgSetVariableAsPropertyXAttribute::rxInit();
      OdDgConstraintsXAttribute::rxInit();
      OdDgECRelationshipXAttribute::rxInit();
      OdDgKMLPlacemarkXAttribute::rxInit();
      OdDgRelationshipNode::rxInit();
      OdDgRelationshipProxyNode::rxInit();
      OdDgRelationshipElementIdNode::rxInit();
      OdDgRelationshipElementIdExtNode::rxInit();
      OdDgRelationshipFarElementIdNode::rxInit();
      OdDgRelationshipFarElementIdExtNode::rxInit();
      OdDgGeometryCacheAction::rxInit();
      OdDgProxyGeometryCacheAction::rxInit();
      OdDgPolyline3dGeometryCacheAction::rxInit();
      OdDgPolyline2dGeometryCacheAction::rxInit();
      OdDgPolygon3dGeometryCacheAction::rxInit();
      OdDgPolygon2dGeometryCacheAction::rxInit();
      OdDgPushTransformGeometryCacheAction::rxInit();
      OdDgPopTransformGeometryCacheAction::rxInit();
      OdDgSetTraitsDataGeometryCacheAction::rxInit();
      OdDgOriginAndRotationGeometryCacheAction::rxInit();
      OdDgByLevelOrGradientDataGeometryCacheAction::rxInit();
      OdDgHatchPatternGeometryCacheAction::rxInit();
      OdDgTextGeometryCacheAction::rxInit();
      OdDgBrepGeometryCacheAction::rxInit();
      OdDgConeGeometryCacheAction::rxInit();
      OdDgMeshGeometryCacheAction::rxInit();
      OdDgBSplineCurve3dGeometryCacheAction::rxInit();
      OdDgBSplineSurfaceGeometryCacheAction::rxInit();
      OdDgBeginSolidGeometryCacheAction::rxInit();
      OdDgBeginExtrusionSolidGeometryCacheAction::rxInit();
      OdDgBeginRevolutionSolidGeometryCacheAction::rxInit();
      OdDgEndSolidGeometryCacheAction::rxInit();
      OdDgBeginComplexGeometryCacheAction::rxInit();
      OdDgBeginComplexStringGeometryCacheAction::rxInit();
      OdDgEndComplexGeometryCacheAction::rxInit();
      OdDgTorusGeometryCacheAction::rxInit();
      OdDgSphereGeometryCacheAction::rxInit();
      OdDgSlabSolidGeometryCacheAction::rxInit();
      OdDgMarkHoleGeometryCacheAction::rxInit();
      OdDgEllipse3dGeometryCacheAction::rxInit();
      OdDgEllipse2dGeometryCacheAction::rxInit();
      OdDgArc3dGeometryCacheAction::rxInit();
      OdDgArc2dGeometryCacheAction::rxInit();
      OdDgModifiedProfileBeginGeometryCacheAction::rxInit();
      OdDgModifiedProfileEndGeometryCacheAction::rxInit();
      OdDgExtraDataSectionBeginGeometryCacheAction::rxInit();
      OdDgExtraDataSectionEndGeometryCacheAction::rxInit();
      OdDgSchemaDescriptionItem::rxInit();
      OdDgCellParamSchemaDescriptionItem::rxInit();
      OdDgTableSchemaDescriptionItem::rxInit();
      OdDgProxySchemaDescriptionItem::rxInit();
      OdDgVariable::rxInit();
      OdDgItemTypeBasedVariable::rxInit();
      OdDgVariableValuesSet::rxInit();
      OdDgVariablesList::rxInit();
      OdDgExpressionVariable::rxInit();
      OdDgExpressionItem::rxInit();
      OdDgProxyExpressionItem::rxInit();
      OdDgConstantValue::rxInit();
      OdDgVariableValue::rxInit();
      OdDgVariableIdValue::rxInit();
      OdDgArithmeticOperator::rxInit();
      OdDgGroupOperator::rxInit();
      OdDgConditionOperator::rxInit();
      OdDgCompareOperator::rxInit();
      OdDgLogicalOperator::rxInit();
      OdDgEqualOrNotOperator::rxInit();
      OdDgNegativeOperator::rxInit();
      OdDgSpecialConstant::rxInit();
      OdDgFunctionOperator::rxInit();
      OdDgElementSchema::rxInit();
      OdDgProxyTableElementSchema::rxInit();
      OdDgPrototypeBasedElementSchema::rxInit();
      OdDgTableDataTableElementSchema::rxInit();
      OdDgMergeDataTableElementSchema::rxInit();
      OdDgFillTableElementSchema::rxInit();
      OdDgSymbologyTableElementSchema::rxInit();
      OdDgEdgeRunTableElementSchema::rxInit();
      OdDgRowTableElementSchema::rxInit();
      OdDgColumnTableElementSchema::rxInit();
      OdDgCellTableElementSchema::rxInit();
      OdDgTablePrototypeItemSchema::rxInit();
      OdDgTablePrototypeHeaderSchema::rxInit();
      OdDgTablePrototypeDescriptionSchema::rxInit();
      OdDgTableSnippedTextSchema::rxInit();
      OdDgPCMCellDefSchema::rxInit();
      OdDgPCMCellSchema::rxInit();
      OdDgConstraintsDataXAttr::rxInit();
      OdDg2dConstraintsDataXAttr::rxInit();
      OdDgDimConstraintsDataXAttr::rxInit();
      OdDgVersionConstraintsDataXAttr::rxInit();
      OdDgIdMapConstraintsDataXAttr::rxInit();
      OdDgElmVisibilityConstraintsDataXAttr::rxInit();
      OdDgConstraintRepresentation::rxInit();
      OdDg2dConstraintRepresentation::rxInit();
      OdDgDimensionalConstraintRepresentation::rxInit();
      OdDgTerrainOptions::rxInit();
      OdDgTerrainOptionsTriangles::rxInit();
      OdDgTerrainOptionsTriangleVertices::rxInit();
      OdDgTerrainOptionsLowPoints::rxInit();
      OdDgTerrainOptionsHighPoints::rxInit();
      OdDgTerrainOptionsFlowArrows::rxInit();
      OdDgTerrainOptionsMinorContour::rxInit();
      OdDgTerrainOptionsMajorContour::rxInit();
      OdDgTerrainOptionsSourceVertices::rxInit();
      OdDgTerrainOptionsSourceBreakLine::rxInit();
      OdDgTerrainOptionsSourceHole::rxInit();
      OdDgTerrainOptionsSourceIsland::rxInit();
      OdDgTerrainOptionsSourceVoid::rxInit();
      OdDgTerrainOptionsSourceBoundary::rxInit();
      OdDgTerrainOptionsSourceContour::rxInit();
      OdDgDimOption::rxInit();
      OdDgDimOptionView::rxInit();
      OdDgDimOptionTerminatorSymbology::rxInit();
      OdDgDimOptionTolerance::rxInit();
      OdDgDimOptionPrefixSuffix::rxInit();
      OdDgDimOptionTerminators::rxInit();
      OdDgDimOptionOffset::rxInit();
      OdDgDimOptionProxyCell::rxInit();
      OdDgDimOptionUnits::rxInit();
      OdDgDimOptionPrimaryUnits::rxInit();
      OdDgDimOptionSecondaryUnits::rxInit();
      OdDgDimOptionAltFormat::rxInit();
      OdDgDimOptionPrimaryAltFormat::rxInit();
      OdDgDimOptionSecondaryAltFormat::rxInit();
      OdDgDimOptionSymbol::rxInit();
      OdDgDimOptionPrefixSuffixSymbol::rxInit();
      OdDgDimOptionPrefixSymbol::rxInit();
      OdDgDimOptionSuffixSymbol::rxInit();
      OdDgDimOptionDiameterSymbol::rxInit();
      OdDgDimOptionAltPrefixSeparator::rxInit();
      OdDgDimOptionAltSuffixSeparator::rxInit();
      pOVar4 = OdDgKMLPlacemarkXAttribute::desc();
      oddgSetXAttributeHandler(0x57190000,pOVar4);
      pOVar4 = OdDgAcsXAttribute::desc();
      oddgSetXAttributeHandler(0x57170001,pOVar4);
      pOVar4 = OdDgAnnotationCellXAttribute::desc();
      oddgSetXAttributeHandler(0x57020000,pOVar4);
      pOVar4 = OdDgTrueColorXAttribute::desc();
      oddgSetXAttributeHandler(0x57090000,pOVar4);
      pOVar4 = OdDgColorBookXAttribute::desc();
      oddgSetXAttributeHandler(0x57040000,pOVar4);
      pOVar4 = OdDgDgnLinkNodeXAttribute::desc();
      oddgSetXAttributeHandler(0x56f50000,pOVar4);
      pOVar4 = OdDgMaterialXAttribute::desc();
      oddgSetXAttributeHandler(0x57080000,pOVar4);
      pOVar4 = OdDgMatProjectionXAttribute::desc();
      oddgSetXAttributeHandler(0x56df0002,pOVar4);
      pOVar4 = OdDgBinXMLXAttribute::desc();
      oddgSetXAttributeHandler(0x56ff0001,pOVar4);
      pOVar4 = OdDgTemplateHeaderXAttribute::desc();
      oddgSetXAttributeHandler(0x583b0001,pOVar4);
      pOVar4 = OdDgTemplateIdXAttribute::desc();
      oddgSetXAttributeHandler(0x583b0004,pOVar4);
      pOVar4 = OdDgRasterClipXAttribute::desc();
      oddgSetXAttributeHandler(0x570b0000,pOVar4);
      pOVar4 = OdDgPdfLayerVisibilityDifXAttribute::desc();
      oddgSetXAttributeHandler(0x570b0007,pOVar4);
      pOVar4 = OdDgTextFieldXAttribute::desc();
      oddgSetXAttributeHandler(0x57050000,pOVar4);
      pOVar4 = OdDgDetailingSymbolXAttribute::desc();
      oddgSetXAttributeHandler(0x57000000,pOVar4);
      pOVar4 = OdDgSectionClipDataXAttribute::desc();
      oddgSetXAttributeHandler(0x6d0000,pOVar4);
      pOVar4 = OdDgSectionClipDataExtXAttribute::desc();
      oddgSetXAttributeHandler(0x6d0001,pOVar4);
      pOVar4 = OdDgEnvironmentMapXAttribute::desc();
      oddgSetXAttributeHandler(0x58750001,pOVar4);
      pOVar4 = OdDgLuxologySetupXAttribute::desc();
      oddgSetXAttributeHandler(0x58750000,pOVar4);
      pOVar4 = OdDgPrintStyleXAttribute::desc();
      oddgSetXAttributeHandler(0x571a0001,pOVar4);
      pOVar4 = OdDgDisplayStyleExtXAttribute::desc();
      oddgSetXAttributeHandler(0x58660000,pOVar4);
      pOVar4 = OdDgLightExtraDataXAttribute::desc();
      oddgSetXAttributeHandler(0x58790000,pOVar4);
      pOVar4 = OdDgDisplayStyleTypeFilterXAttribute::desc();
      oddgSetXAttributeHandler(0x58ea1000,pOVar4);
      pOVar4 = OdDgDisplayStyleLegendXAttribute::desc();
      oddgSetXAttributeHandler(0x58ea1001,pOVar4);
      pOVar4 = OdDgDefaultTextStyleXAttribute::desc();
      oddgSetXAttributeHandler(0x586b0001,pOVar4);
      pOVar4 = OdDgDisplayStyleAzimuthAltitudeXAttribute::desc();
      oddgSetXAttributeHandler(0x58ea1003,pOVar4);
      pOVar4 = OdDgDisplayStyleNumberXAttribute::desc();
      oddgSetXAttributeHandler(0x586a0000,pOVar4);
      pOVar4 = OdDgClipVolumeSettingsXAttribute::desc();
      oddgSetXAttributeHandler(0x58620000,pOVar4);
      pOVar4 = OdDgTerrainVertexCoordinatesXAttribute::desc();
      oddgSetXAttributeHandler(0x58ec012e,pOVar4);
      pOVar4 = OdDgTerrainVertexTopologyXAttribute::desc();
      oddgSetXAttributeHandler(0x58ec012f,pOVar4);
      pOVar4 = OdDgTerrainEdgesXAttribute::desc();
      oddgSetXAttributeHandler(0x58ec0130,pOVar4);
      pOVar4 = OdDgTerrainStringXAttribute::desc();
      oddgSetXAttributeHandler(0x587a0000,pOVar4);
      pOVar4 = OdDgTerrainTransformationXAttribute::desc();
      oddgSetXAttributeHandler(0x58ec014e,pOVar4);
      pOVar4 = OdDgTerrainInfoXAttribute::desc();
      oddgSetXAttributeHandler(0x58ec012c,pOVar4);
      pOVar4 = OdDgTerrainFeatureDescriptionXAttribute::desc();
      oddgSetXAttributeHandler(0x58ec012d,pOVar4);
      pOVar4 = OdDgTerrainFeatureTopologyXAttribute::desc();
      oddgSetXAttributeHandler(0x58ec0131,pOVar4);
      pOVar4 = OdDgTerrainCorruptedFeatureXAttribute::desc();
      oddgSetXAttributeHandler(0x58ec0140,pOVar4);
      pOVar4 = OdDgExtendedElementTypeXAttribute::desc();
      oddgSetXAttributeHandler(0x56ec0000,pOVar4);
      pOVar4 = OdDgTerrainGraphicsSettingsXAttribute::desc();
      oddgSetXAttributeHandler(0x58ec0136,pOVar4);
      pOVar4 = OdDgTerrainDisplayStyleXAttribute::desc();
      oddgSetXAttributeHandler(0x58ec0001,pOVar4);
      pOVar4 = OdDgTerrainControlReferenceXAttribute::desc();
      oddgSetXAttributeHandler(0x58ec0064,pOVar4);
      pOVar4 = OdDgTextStyleDataXAttribute::desc();
      oddgSetXAttributeHandler(0x58010001,pOVar4);
      pOVar4 = OdDgItemLibNameXAttribute::desc();
      oddgSetXAttributeHandler(0x56d2003d,pOVar4);
      pOVar4 = OdDgItemLibVersionXAttribute::desc();
      oddgSetXAttributeHandler(0x56d20050,pOVar4);
      pOVar4 = OdDgItemLibProviderXAttribute::desc();
      oddgSetXAttributeHandler(0x56d20054,pOVar4);
      pOVar4 = OdDgItemTypeXAttribute::desc();
      oddgSetXAttributeHandler(0x56ff0000,pOVar4);
      pOVar4 = OdDgGeometryCacheXAttribute::desc();
      oddgSetXAttributeHandler(0x57180000,pOVar4);
      pOVar4 = OdDgElementSchemaXAttribute::desc();
      oddgSetXAttributeHandler(0xecda0000,pOVar4);
      pOVar4 = OdDgSchemaDescriptionXAttribute::desc();
      oddgSetXAttributeHandler(0xec5c0000,pOVar4);
      pOVar4 = OdDgMaterialTableExtXAttribute::desc();
      oddgSetXAttributeHandler(0x570a0000,pOVar4);
      pOVar4 = OdDgSetVariableAsPropertyXAttribute::desc();
      oddgSetXAttributeHandler(0x58e4000a,pOVar4);
      pOVar4 = OdDgConstraintsXAttribute::desc();
      oddgSetXAttributeHandler(0x56da0001,pOVar4);
      pOVar4 = OdDgECRelationshipXAttribute::desc();
      oddgSetXAttributeHandler(0x57160001,pOVar4);
      FUN_1805b0a90();
      OdDgSelectionSetIterator::rxInit();
      OdDgSelectionSet::rxInit();
      OdDgCommandContext::rxInit();
      OdDgUserIO::rxInit();
      OdDgGripPointsPE::rxInit();
      OdDgGeoDataPE::rxInit();
      OdDgGeoDataCoordinateSystemCategoryPE::rxInit();
      OdDgGeoDataReprojectionPE::rxInit();
      OdDgGeoMapImagePE::rxInit();
      OdDgDeepCloneFiler::rxInit();
      OdDgWblockCloneFiler::rxInit();
      OdDgIdMapping::rxInit();
      OdDgIdMappingIter::rxInit();
      FUN_1809ee9c0();
      FUN_1809eeba0();
      FUN_1809ef940();
      OdDgProxyClass::rxInit();
      OdDgTransformOverrule::rxInit();
      OdDgElementOverrule::rxInit();
      OdDgGripOverrule::rxInit();
      OdDgPropertiesOverrule::rxInit();
      OdDgOsnapOverrule::rxInit();
      OdDgHighlightOverrule::rxInit();
      OdDgVisibilityOverrule::rxInit();
      OdDgGeometryOverrule::rxInit();
      OdDgTransactionReactor::rxInit();
      FUN_18078aa90();
      FUN_18078b030();
      if (plVar1 != (longlong *)0x0) {
        (**(code **)(*plVar1 + 0x28))(plVar1);
      }
      return;
    }
    OdError::OdError((OdError *)&local_res18,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_res18,(ThrowInfo *)&DAT_180de52b8);
  }
  OdError::OdError((OdError *)&local_res18,0x13a);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_res18,(ThrowInfo *)&DAT_180de52b8);
}



